/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:42:27 by joeduard          #+#    #+#             */
/*   Updated: 2022/05/27 19:42:31 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtins(char *cmd)
{
	int		i;
	int		switcher;
	char	*builtin_cmd[NUMBER_OF_BUILTINS];

	i = -1;
	switcher = 0;
	builtin_cmd[0] = "exit";
	builtin_cmd[1] = "cd";
	builtin_cmd[2] = "echo";
	builtin_cmd[3] = "pwd";
	builtin_cmd[4] = "env";
	builtin_cmd[5] = "export";
	builtin_cmd[6] = "unset";
	if (!cmd)
		return (0);
	while (++i < NUMBER_OF_BUILTINS)
	{
		if (ft_strcmp(cmd, builtin_cmd[i]) == 0)
		{
			switcher = i + 1;
			break ;
		}
	}
	return (switcher);
}
