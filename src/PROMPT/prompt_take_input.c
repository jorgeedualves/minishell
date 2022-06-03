/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_take_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:45:38 by joeduard          #+#    #+#             */
/*   Updated: 2022/06/02 02:37:21 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt(t_data *data)
{
	printf("--PROMPT_TAKE_INPUT.C---->[prompt]\n");
	char	cwd[1024];
	char	*prompt_str;
	char	*username;

	username = getenv("USER");
	getcwd(cwd, sizeof(cwd));
	prompt_str = ft_mult_join(7, "\e[32m", username, ":", \
							"\e[35m", cwd, "\e[0m", "$ ");
	data->input = readline(prompt_str);
	free(prompt_str);
	printf("[------ saida [prompt] -------------------]\n");
}

/** Function to take input - MALLOC input*/
int	take_input(t_data *data)
{
	printf("\n[--------------------------]\n");
	printf("--PROMPOT_TAKE_INPUT.C---->[take input]\n");
	prompt(data);
	if (!data->input)
		exit_minishell(data, SUCCESS);
	if (ft_strlen(data->input) != 0)
	{
		if (is_space_str(data->input))
			return (FAILURE);
		put_on_history(data->input, data->old_input);
		if (data->old_input)
			free(data->old_input);
		data->old_input = ft_strdup(data->input);
		printf("[------ saida [take input]-------------------]\n");
		return (SUCCESS);
	}
	else
	{
		printf("[------ saida [take input]-------------------]\n");
		return (FAILURE);
	}

}
