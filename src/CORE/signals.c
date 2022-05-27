/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:39:33 by joeduard          #+#    #+#             */
/*   Updated: 2022/05/27 19:39:41 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Creates a new prompt.
*/
void	new_prompt_mini(int signal)
{
	(void)signal;
	g_status_code = 130;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

/*
	Handling signals for child process.
*/
void	handler(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		g_status_code = 130;
	}
	else
	{
		printf("Quit (core dumped)\n");
		g_status_code = 131;
	}
}

void	exec_signals(void)
{
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
}

void	interrupt_input_writing(int signal)
{
	(void)signal;
	write(1, "\n", 1);
	exit(130);
}
