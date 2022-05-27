/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:35:39 by joeduard          #+#    #+#             */
/*   Updated: 2022/05/27 19:35:42 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env(t_data *data)
{
	int		i;

	i = 0;
	while (data->envp[i])
		printf("%s\n", data->envp[i++]);
	return (SUCCESS);
}
