/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:35:39 by joeduard          #+#    #+#             */
/*   Updated: 2022/06/02 13:38:04 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env(t_data *data)
{
	printf("\n[---------------------------------]\n");
	printf("--ENV.C---->[env]");
	int		i;

	i = 0;
	while (data->envp[i])
		printf("%s\n", data->envp[i++]);
	printf("[------ saida [env]-SUCCESS----------]\n");
	return (SUCCESS);
}
