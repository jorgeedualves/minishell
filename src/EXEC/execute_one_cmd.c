/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_one_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:40:59 by joeduard          #+#    #+#             */
/*   Updated: 2022/06/02 02:25:52 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	restore_std_fds(int *fd);

int	execute_one_cmd(t_data *data)
{
	printf("\n[--------------------------]\n");
	printf("--EXECUTE_ONE_CMD.C---->[execute_one_cmd]\n");
	int		save_fd[2];
	int		builtin;

	builtin = is_builtins(data->argve[0][0]);
	save_std_fds(save_fd);
	if (!redirect_filter(data, 0, save_fd))
		builtin_exec(data, builtin, 0);
	restore_std_fds(save_fd);
	printf("[------ saida [execute_one_cmd]-------------------]\n");
	return (SUCCESS);
}

static void	restore_std_fds(int *fd)
{
	printf("--EXECUTE_ONE_CMD.C---->[restore_std_fds]\n");
	dup2(fd[STDOUT], STDOUT_FILENO);
	close(fd[STDOUT]);
	dup2(fd[STDIN], STDIN_FILENO);
	close(fd[STDIN]);
	printf("[------ saida [restore_std_fds]-------------------]\n");
}

void	save_std_fds(int *fd)
{
	printf("--EXECUTE_ONE_CMD.C---->[save_std_fds]\n");
	fd[STDIN] = dup(STDIN_FILENO);
	fd[STDOUT] = dup(STDOUT_FILENO);
	printf("[------ saida [save_std_fds]-------------------]\n");
}
