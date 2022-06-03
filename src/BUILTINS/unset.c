/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:37:27 by joeduard          #+#    #+#             */
/*   Updated: 2022/06/02 02:22:55 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset(t_data *data, int id)
{
	printf("\n[--------------------------]\n");
	printf("--UNSET.C---->[unset]\n");
	int		i;
	int		arglen;
	int		arg;

	arg = 1;
	while (data->argve[id][arg])
	{
		i = 0;
		while (data->envp[i])
		{
			if (!ft_strcmp(data->argve[id][arg], "PATH"))
				double_free((void ***)&data->command_path);
			arglen = ft_strlen(data->argve[id][arg]);
			if (!ft_strncmp(data->envp[i], data->argve[id][arg], arglen) && \
				data->envp[i][arglen] == '=')
			{
				free(data->envp[i]);
				move_ptrs_back(data->envp + i);
			}
			else
				i++;
		}
		delete_in_list(data->argve[id][arg++], &data->vars);
	}
	printf("[------ saida [unset]-------------------]\n");
}
