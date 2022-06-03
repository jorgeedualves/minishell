/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull_redirects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:43:44 by joeduard          #+#    #+#             */
/*   Updated: 2022/06/02 02:34:52 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define DIFF_REDIR	"minishell: syntax error near unexpected token `%c'"
#define BL_IN_REDIR	"minishell: syntax error near unexpected token `newline'"

static void	malloc_file(t_data *data, int string_level, int k, int bytes);
static int	count_redirects(char *str);
static int	save_file(char *cmd, char **file);
static void	find_redirects(t_data *data, int id);

int	pull_redirects(t_data *data)
{
	printf("\n[--------------------------]\n");
	printf("--PULL_REDIRECTS.C---->[pull_redirects]\n");
	int		id;					// id of the redirect
	int		redirects_nbr;		// number of redirects

	id = 0;
	malloc_file(data, 0, 0, data->number_of_pipes + 2);			// +2 for the '\n' and '\0'
while (data->cmds_piped[id])
	{
		redirects_nbr = count_redirects(data->cmds_piped[id]);
		if (redirects_nbr == -1)
		{
			g_status_code = SINTAX_ERR;
			return (FAILURE);
		}
		malloc_file(data, 1, id, redirects_nbr + 1);
		if (redirects_nbr)
			find_redirects(data, id);
		unmask_character(data->cmds_piped[id], 4, '>');
		unmask_character(data->cmds_piped[id], 5, '<');
		id++;
	}
	printf("[------ saida [pull_redirects]-----------------]\n");
	return (SUCCESS);
}

static void	find_redirects(t_data *data, int id)
{
	printf("--PULL_REDIRECTS.C---->[find_redirects]\n");
	int		i;
	int		j;
	int		init;

	i = -1;
	j = 0;
	while (data->cmds_piped[id][++i])
	{
		if (!ft_strchr("><", data->cmds_piped[id][i]))
			continue ;
		init = i;
		if (data->cmds_piped[id][i] == '>')
			data->file_mode[id][j] = GREAT;
		else if (data->cmds_piped[id][i] == '<')
			data->file_mode[id][j] = LESS;
		if (data->cmds_piped[id][i] == data->cmds_piped[id][i + 1])
			data->file_mode[id][j] *= 2;
		i += 1 + (!(data->file_mode[id][j] % 2));
		i += save_file(data->cmds_piped[id] + i, &data->file[id][j]);
		ft_strcut(&data->cmds_piped[id], init, i);
		i = init - 1;
		if (!data->file[id][j] || !data->cmds_piped[id])
			exit_minishell(data, FAILURE);
		j++;
	}
	printf("[------ saida [find_redirects]-----------------]\n");
}

static int	save_file(char *cmd, char **file)
{
	printf("--PULL_REDIRECTS.C---->[save_file]\n");
	int		end;
	int		init;

	end = 0;
	while (cmd[end] == ' ' && cmd[end])
		end++;
	init = end;
	while (!ft_strchr(" ><", cmd[end]) && cmd[end])
		end++;
	if (cmd[end])
		end--;
	*file = ft_substr(cmd, init, end);
	if (cmd[end])
		end++;
	printf("[------ saida [save_file]-----------------]\n");
	return (end);
}

static int	count_redirects(char *s)
{
	printf("--PULL_REDIRECTS.C---->[count_redirects]\n");
	int		i;
	int		j;
	int		redirects_nbr;

	i = -1;
	redirects_nbr = 0;
	while (s[++i])
	{
		if (s[i] != '>' && s[i] != '<')
			continue ;
		j = i;
		while (ft_strchr("><", s[i]) && s[i])
			i++;
		if ((s[j] != s[j + 1] && ft_strchr("><", s[j + 1])) || i - j > 2)
			ft_printf(STDERR, DIFF_REDIR, s[i + 1 + (j - i > 2)]);
		else if (!s[i])
			ft_printf(STDERR, BL_IN_REDIR);
		else
		{
			redirects_nbr++;
			continue ;
		}
		printf("[------ saida [save_file]-----------------]\n");
		return (-1);
	}
	printf("[------ saida [save_file]-----------------]\n");
	return (redirects_nbr);
}

static void	malloc_file(t_data *data, int string_level, int id, int bytes)
{
	printf("--PULL_REDIRECTS.C---->[malloc_file]\n");
	if (!string_level)
	{
		data->file = (char ***)ft_calloc(sizeof(char **), bytes);
		data->file_mode = (char **)ft_calloc(sizeof(char *), bytes);
		if (!data->file || !data->file_mode)
		{
			printf("[------ saida [malloc_file]-----------------]\n");
			exit_minishell(data, FAILURE);
		}
	}
	else
	{
		data->file[id] = (char **)ft_calloc(sizeof(char *), bytes);
		data->file_mode[id] = (char *)ft_calloc(sizeof(char), bytes);
		if (!data->file[id] || !data->file_mode[id])
		{
			printf("[------ saida [malloc_file]-----------------]\n");
			exit_minishell(data, FAILURE);
		}
	}
}
