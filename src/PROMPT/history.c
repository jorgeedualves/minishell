/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:45:23 by joeduard          #+#    #+#             */
/*   Updated: 2022/06/02 02:37:07 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_on_history(char *buf, char *old_input)
{
	printf("\n[--------------------------]\n");
	printf("--LIST_TOOLS_ONE.C---->[put_on_history]\n");
	if (!old_input || ft_strcmp(old_input, buf))
	{
		printf("[------ saida [put_on_history]-------------------]\n");
		add_history(buf);
	}
}
