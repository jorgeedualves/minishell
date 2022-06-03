/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:39:24 by joeduard          #+#    #+#             */
/*   Updated: 2022/06/02 02:25:14 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(t_data *data)
{
	printf("\n[--------------------------]\n");
	printf("--MINISHELL.C---->[minishell]\n");
	signal(SIGINT, new_prompt_mini);
	signal(SIGQUIT, SIG_IGN);
	data_clean(data);
	if (take_input(data) || lexer(data))
		return ;
	expander(data);
	if (parser(data))
		return ;
	executor(data);
	printf("[------ saida [minishell]-------------------]\n");
}
