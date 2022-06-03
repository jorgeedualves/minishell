/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:42:38 by joeduard          #+#    #+#             */
/*   Updated: 2022/06/02 02:47:11 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// finds the variables on argve
int	find_vars(char **argve)
{
	printf("\n[--------------------------]\n");
	printf("--EXPAND_UTILS.C---->[find_vars]\n");
	int	i;

	i = 0;
	if (!argve)
		return (-1);
	while (argve[i])
	{
		if (ft_strchr(argve[i], '$'))
			return (i);
		i++;
	}
	printf("[------ saida [find_vars]-------------------]\n");
	return (-1);
}

// creates space on the argve for the expanded variables
void	make_space(char **argve, int start)
{
	printf("--EXPAND_UTILS.C---->[make_space]\n");
	int	i;

	i = 0;
	while (argve[i])
		i++;
	argve[i + 1] = NULL;
	while (i > start)
	{
		if (argve[i])
			free(argve[i]);
		argve[i] = ft_strdup(argve[i - 1]);
		i--;
	}
	free(argve[i]);
	printf("[------ saida [make_space]-------------------]\n");
}

// allocates a bigger argve, copies the old to the new one and frees the old one
char	**new_argve(char *value, t_data *data, int id)
{
	printf("--EXPAND_UTILS.C---->[new_argve]\n");
	char	**cmdstr;
	char	**temp_argve;
	int		cmdstr_size;
	int		argve_size;

	cmdstr = ft_split(value, ' ');
	cmdstr_size = ft_str_count(cmdstr);
	argve_size = ft_str_count(data->argve[id]);
	temp_argve = (char **)malloc((cmdstr_size + argve_size + 1) * \
		sizeof(char *));
	ft_memcpy(temp_argve, data->argve[id], argve_size * sizeof(char *));
	free(data->argve[id]);
	data->argve[id] = temp_argve;
	data->argve[id][argve_size] = 0x0;
	printf("[------ saida [new_argve]-------------------]\n");
	return (cmdstr);
}

// makes room for new args and inserts it into data structure
void	insert_new_args(t_data *data, char **cmdstr, int i, int id)
{
	printf("\n[--------------------------]\n");
	printf("--EXPAND_UTILS.C---->[insert_new_args]\n");
	free(data->argve[id][i]);
	data->argve[id][i] = ft_strdup(*cmdstr);
	while (*(++cmdstr))
	{
		make_space(data->argve[id], ++i);
		data->argve[id][i] = ft_strdup(*cmdstr);
	}
	printf("[------ saida [insert_new_args]-------------------]\n");
}
