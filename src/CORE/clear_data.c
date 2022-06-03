/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:38:28 by joeduard          #+#    #+#             */
/*   Updated: 2022/06/02 15:08:32 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	data_clean(t_data *data)
{
	printf("\n[--------------------------]\n");
	printf("--CLEAR_DATA.C---->[data_clear]\n");
	if (data->input)
		free(data->input);
	if (data->pid)
		free(data->pid);
	data->input = NULL;
	data->pid = NULL;
	double_free((void ***)&data->fd);
	double_free((void ***)&data->cmds_piped);
	double_free((void ***)&data->file_mode);
	triple_free(&data->file, data->number_of_pipes + 1);
	triple_free(&data->argve, data->number_of_pipes + 1);
	data->number_of_pipes = GARBAGE;
	if (data->exec_flag)
		free(data->exec_flag);
	data->exec_flag = NULL;
	printf("[------ saida [data_clear]-------------------]\n");
}

void	double_free(void ***ptr)
{
	printf("--CLEAR_DATA.C---->[double_free]\n");
	int		i;

	i = 0;
	if (!*ptr)
	{
		printf("[------ saida [data_clear]--*ptr nao é NULL-----------------]\n");
		return ;
	}
	while ((*ptr)[i])
	{
		if ((*ptr)[i])
			free((*ptr)[i]);
		(*ptr)[i] = NULL;
		i++;
	}
	free(*ptr);
	*ptr = NULL;
	printf("[------ saida [double_free]------------------]\n");
}

void	triple_free(char ****ptr, int number_of_ids)
{
	printf("--CLEAR_DATA.C---->[triple_free]\n");
	int		id;
	int		cmd;

	if (!*ptr)
		return ;
	id = 0;
	while (id < number_of_ids)
	{
		if ((*ptr)[id])
		{
			cmd = 0;
			while ((*ptr)[id][cmd])
			{
				if ((*ptr)[id][cmd])
					free((*ptr)[id][cmd]);
				(*ptr)[id][cmd] = NULL;
				cmd++;
			}
			free((*ptr)[id]);
			(*ptr)[id] = NULL;
		}
		id++;
	}
	free(*ptr);
	*ptr = NULL;
	printf("[------ saida [triple_free]------------------]\n");
}
