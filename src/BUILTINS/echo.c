/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:35:17 by joeduard          #+#    #+#             */
/*   Updated: 2022/06/02 13:37:12 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_n_flag(t_data *data, int id, int *index);
static int	is_n_str(char *s);

void	echo(t_data *data, int id)
{
	printf("\n[--------------------------]\n");
	printf("--ECHO.C---->[echo]\n");
	int	break_line;
	int	index;

	index = 1;
	if (data->argve[id][index])
	{
		break_line = is_n_flag(data, id, &index);
		while (data->argve[id][index])
		{
			ft_putstr_fd(data->argve[id][index], 1);
			if (data->argve[id][++index])
				ft_putchar_fd(' ', 1);
		}
		if (break_line)
			ft_putstr_fd("\n", 1);
	}
	else
		ft_putstr_fd("\n", 1);
	printf("[------ saida [echo]-------------------]\n");
}

static int	is_n_flag(t_data *data, int id, int *index)
{
	printf("--ECHO.C---->[is_n_flag]\n");
	int	break_line;

	break_line = 1;
	while (data->argve[id][*index])
	{
		if (!ft_strncmp(data->argve[id][*index], "-n", 2))
		{
			if (data->argve[id][*index][2] == '\0' ||
				is_n_str(data->argve[id][*index] + 2))
			{
				break_line = 0;
				(*index)++;
			}
			else
				break ;
		}
		else
			break ;
	}
	printf("[------ saida [is_n_flag]-------------------]\n");
	return (break_line);
}

static int	is_n_str(char *s)
{
	printf("--ECHO.C---->[is_n_str]\n");
	while (*s)
	{
		if (*s != 'n')
		{
			printf("[------ saida [is_n_str]-FALSE-------------]\n");
			return (FALSE);
		}
		s++;
	}
	printf("[------ saida [is_n_str]-TRUE--------------]\n");
	return (TRUE);
}
