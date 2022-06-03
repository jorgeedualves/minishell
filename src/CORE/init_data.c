/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:38:45 by joeduard          #+#    #+#             */
/*   Updated: 2022/06/02 02:51:45 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	backup_envp_parameter(t_data *data, char **envp);
static void	fill_list_vars(t_data *data);

void	init_data(t_data *data, char **envp)
{	
	printf("\n[--------------------------]\n");
	printf("--INIT_DATA.C---->[init_data]\n");
	ft_bzero(data, sizeof(t_data));
	data->envp = (char **)ft_calloc(ft_str_count(envp) + 1, sizeof(char *));
	if (!data->envp)
		exit_minishell(data, FAILURE);
	backup_envp_parameter(data, envp);
	fill_list_vars(data);
	update_command_path(data);
	data->number_of_pipes = GARBAGE;
	data->exec_flag = NULL;
	printf("[------ saida [init_data]-------------------]\n");
}

int	update_command_path(t_data *data)
{
	printf("--INIT_DATA.C---->[update_command_path]\n");
	int		i;
	t_vdt	vdt;

	vdt = find_in_list("PATH", data->vars);
	if (data->command_path)
		double_free((void ***)&data->command_path);
	data->command_path = ft_split(vdt.value, ':');
	if (!data->command_path)
	{
		perror("Minishell: [data>command_path] Malloc error");
		return (FAILURE);
	}
	i = 0;
	while (data->command_path[i] != NULL)
	{
		if (ft_strjoin_handled(&(data->command_path[i]), "/") == FAILURE)
		{
			ft_putstr_fd("Init failed\n", 2);
			exit_minishell(data, FAILURE);
		}
		i++;
	}
	printf("[------ saida [update_command_path]-------------------]\n");
	return (SUCCESS);
}

static void	backup_envp_parameter(t_data *data, char **envp)
{

	printf("--INIT_DATA.C---->[back_envp_parameter]\n");
	int		i;

	i = 0;
	while (envp[i])
	{
		data->envp[i] = ft_strdup(envp[i]);
		if (!data->envp[i])
			exit_minishell(data, FAILURE);
		i++;
	}
	printf("[------ saida [back_envp_parameter]-------------------]\n");
}

static void	fill_list_vars(t_data *data)
{
	printf("--INIT_DATA.C---->[fill_list_vars]\n");
	int		i;
	t_vars	*temp;

	i = 0;
	while (data->envp[i])
	{
		grab_vars(data, data->envp[i]);
		temp = last_in_list(data->vars);
		temp->env = i++;
	}
	printf("[------ saida [fill_list_vars]-------------------]\n");
}
