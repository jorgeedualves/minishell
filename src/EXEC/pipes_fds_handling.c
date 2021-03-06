/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_fds_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:41:45 by joeduard          #+#    #+#             */
/*   Updated: 2022/06/02 02:26:27 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_pipes(t_data *data)
{
	printf("\n[--------------------------]\n");
	printf("--PIPES_FDS_HANDLING.C---->[open_pipes]\n");
	int	id;
	int	j;

	id = 0;
	while (id < data->number_of_pipes)
	{
		if ((pipe(data->fd[id++])) < 0)
		{
			perror("Minishell: Could not open pipe");
			j = 0;
			while (j < id)
			{
				close(data->fd[j][0]);
				close(data->fd[j][1]);
				j++;
			}
			return (FAILURE);
		}
	}
	printf("\n[--------------------------]\n");
	return (SUCCESS);
}

int	close_other_fds(int id, t_data *data)
{
		printf("--PIPES_FDS_HANDLING.C---->[close_other_fds]\n");
	int	j;

	j = 0;
	while (j < data->number_of_pipes)
	{
		if (j != id)
			close(data->fd[j][1]);
		if (j != id - 1)
			close(data->fd[j][0]);
		j++;
	}
	return (SUCCESS);
}

int	stdin_stdout_handler(int in, int out)
{
	printf("--PIPES_FDS_HANDLING.C---->[stdin_stdout_handler]\n");
	if (in != NOT_EXIST)
	{
		dup2(in, STDIN_FILENO);
		close(in);
	}
	if (out != NOT_EXIST)
	{
		dup2(out, STDOUT_FILENO);
		close(out);
	}
	return (SUCCESS);
}

int	file_descriptor_handler(int id, t_data *data)
{
	printf("--PIPES_FDS_HANDLING.C---->[file_descriptor_handler]\n");
	int	fd_in;
	int	fd_out;

	fd_in = 0;
	fd_out = 0;
	if (id == 0)
		fd_in = NOT_EXIST;
	if (id == data->number_of_pipes)
		fd_out = NOT_EXIST;
	if (fd_in != NOT_EXIST)
		fd_in = data->fd[id - 1][0];
	if (fd_out != NOT_EXIST)
		fd_out = data->fd[id][1];
	stdin_stdout_handler(fd_in, fd_out);
	printf("[------ saida [file_descriptor_handler]------------------]\n");
	return (SUCCESS);
}
