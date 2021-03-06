/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:41:57 by joeduard          #+#    #+#             */
/*   Updated: 2022/06/02 02:26:33 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	main_process_handler(t_data *data)
{
	printf("\n[--------------------------]\n");
	printf("--PROCESSES_HANDLER.C---->[main_process_handler]\n");
	int	count;
	int	status;

	count = 0;
	while (count < data->number_of_pipes)
	{
		close(data->fd[count][0]);
		close(data->fd[count][1]);
		count++;
	}
	count = 0;
	while (count < data->number_of_pipes + 1)
	{
		waitpid(data->pid[count++], &status, 0);
		if (!g_status_code)
			g_status_code = WEXITSTATUS(status);
	}
	printf("\n[------ saida [ain_process_handler]------------------]\n");	
}

void	create_executor_parametes(t_data *data)
{
	printf("--PROCESSES_HANDLER.C---->[create-executor_parametes]\n");
	int		i;

	i = 0;
	data->pid = (int *)ft_calloc(sizeof(int), data->number_of_pipes + 1);
	data->fd = (int **)ft_calloc(sizeof(int *), data->number_of_pipes + 1);
	if (!data->pid || !data->fd)
		exit_minishell(data, FAILURE);
	while (i < data->number_of_pipes)
	{
		data->fd[i] = (int *)malloc(sizeof(int) * 2);
		if (!data->fd[i])
			exit_minishell(data, FAILURE);
		i++;
	}
	printf("[------ saida [create-executor_parametes]------------------]\n");
}
