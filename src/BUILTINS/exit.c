/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:35:50 by joeduard          #+#    #+#             */
/*   Updated: 2022/06/02 15:32:32 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	isdigitstr(char *str);

int	exit_minishell(t_data *data, int status)
{	
	printf("--EXIT.C---->[exit_minishell]\n");
	data_clean(data);
	if (data->old_input)
		free(data->old_input);
	double_free((void ***)&data->command_path);
	double_free((void ***)&data->envp);
	clear_list(data->vars);
	rl_clear_history();
	free(data);
	printf("[------ saida [exit]-------------------]\n");
	exit(g_status_code | status);
}

void	mini_exit(t_data *data, int id)
{
	printf("\n[--------------------------]\n");
	printf("--EXIT.C---->[mini_exit]\n");
	int		args;

	args = ft_str_count(data->argve[id]);
	if (args > 2)
	{
		if (isdigitstr(data->argve[id][1]))
			ft_printf(STDERR, "Minishell: exit: too many arguments\n");
		else
		{
			printf("[------ saida [mini_exit]-------------------]\n");
			exit_minishell(data, 2);
		}
	}		
	else
	{
		if (data->number_of_pipes < 1)
			printf("Goodbye!\n");
		if (args == 1)
			exit_minishell(data, 0);
		else if (args == 2)
			exit_minishell(data, ft_atoi(data->argve[id][1]));
	}
	g_status_code = 1;
	printf("[------ saida [mini_exit]----g_status_code = 1---------------]\n");
}

static int	isdigitstr(char *str)
{
	printf("--EXIT.C---->[isdigitstr]\n");
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			printf("[------ saida [isdigitstr]-FALSE-------------]\n");
			return (FALSE);
		}	
		str++;
	}
	printf("[------ saida [isdigitstr]-TRUE--------------]\n");
	return (TRUE);
}
