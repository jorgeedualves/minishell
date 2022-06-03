/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tools_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:46:46 by joeduard          #+#    #+#             */
/*   Updated: 2022/06/02 02:40:55 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_space(int c);

int	is_space_str(char *s)
{
	printf("\n[-------------------------]\n");
	printf("--STR_TOOLS_TWO.C---->[is_space_str]\n");
	size_t	i;

	i = 0;
	while (s[i] && is_space(s[i]))
		i++;
	if (i == ft_strlen(s))
	{
		printf("[------ saida [is_space_str]-------------------]\n");
		return (TRUE);
	}
	printf("[------ saida [is_space_str]-------------------]\n");
	return (FALSE);
}

static int	is_space(int c)
{
	printf("--STR_TOOLS_TWO.C---->[is_space]\n");
	if (c == ' ')
	{
		printf("[------ saida [is_space]-------------------]\n");
		return (TRUE);
	}
	printf("[------ saida [is_space]-------------------]\n");
	return (0);
}
