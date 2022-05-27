/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_one_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:40:59 by joeduard          #+#    #+#             */
/*   Updated: 2022/05/27 19:41:04 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	restore_std_fds(int *fd);

int	execute_one_cmd(t_data *data)
{
	int		save_fd[2];
	int		builtin;

	builtin = is_builtins(data->argve[0][0]);
	save_std_fds(save_fd);
	if (!redirect_filter(data, 0, save_fd))
		builtin_exec(data, builtin, 0);
	restore_std_fds(save_fd);
	return (SUCCESS);
}

static void	restore_std_fds(int *fd)
{
	dup2(fd[STDOUT], STDOUT_FILENO);
	close(fd[STDOUT]);
	dup2(fd[STDIN], STDIN_FILENO);
	close(fd[STDIN]);
}

void	save_std_fds(int *fd)
{
	fd[STDIN] = dup(STDIN_FILENO);
	fd[STDOUT] = dup(STDOUT_FILENO);
}
