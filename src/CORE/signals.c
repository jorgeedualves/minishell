/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:39:33 by joeduard          #+#    #+#             */
/*   Updated: 2022/06/02 02:25:38 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Creates a new prompt.
*/
void	new_prompt_mini(int signal)
{
	printf("\n[--------------------------]\n");
	printf("--SIGNAL.C---->[new_prompt_mini]\n");
	(void)signal;
	g_status_code = 130;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	printf("[------ saida [new_prompt_mini]-------------------]\n");
}

/*
	Handling signals for child process.
*/
void	handler(int signal)
{
	printf("--SIGNAL.C---->[handler]\n");
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
	printf("[------ saida [handler]-------------------]\n");
}

void	exec_signals(void)
{
	printf("--SIGNAL.C---->[exec_signals]\n");
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
	printf("[------ saida [exec_signals]-------------------]\n");
}

void	interrupt_input_writing(int signal)
{
	printf("--SIGNAL.C---->[interrupt_input_writing]\n");
	(void)signal;
	write(1, "\n", 1);
	exit(130);
	printf("[------ saida [interrupt_input_writing]-------------------]\n");
}
