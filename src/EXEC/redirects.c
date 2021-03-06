/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:42:14 by joeduard          #+#    #+#             */
/*   Updated: 2022/06/02 02:26:48 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	redirect(char *file, int flags, int std_fd);

int	redirect_filter(t_data *data, int id, int *save_fd)
{
	printf("\n[--------------------------]\n");
	printf("--REDIRECT.C---->[redirect]\n");
	int	i;
	int	status;

	if (!data->file[id])
		return (SUCCESS);
	status = 0;
	i = 0;
	while (data->file_mode[id][i] && !status)
	{
		if (data->file_mode[id][i] == GREAT)
			status = redirect(data->file[id][i], \
				O_WRONLY | O_CREAT | O_TRUNC, STDOUT);
		else if (data->file_mode[id][i] == GREATGREAT)
			status = redirect(data->file[id][i], \
				O_WRONLY | O_CREAT | O_APPEND, STDOUT);
		else if (data->file_mode[id][i] == LESS)
			status = redirect(data->file[id][i], O_RDONLY, STDIN);
		else if (data->file_mode[id][i] == LESSLESS)
			if (heredoc(data->file[id][i], save_fd))
				return (-1);
		i++;
	}
	if (!data->argve[id][0])
		exit(FAILURE);
	return (status);
}

static int	redirect(char *file, int flags, int std_fd)
{
	printf("--REDIRECT.C---->[redirect]\n");
	int	fd;

	if (!std_fd)
		fd = open(file, flags);
	else
		fd = open(file, flags, 0777);
	if (fd == -1)
		perror("Minishell: Open function failed");
	else
	{
		dup2(fd, std_fd);
		close(fd);
		printf("\n[------ saida [redirect]-SUCESS---------]\n");
		return (SUCCESS);
	}
	g_status_code = 1;
	printf("[------ saida [redirect]-FAILURE----------]\n");
	return (FAILURE);
}
