/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask_n_unmask_chars.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:43:34 by joeduard          #+#    #+#             */
/*   Updated: 2022/06/02 17:23:13 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define UNCLOSED_QUOTES "Minishell: Sintaxe Error: Unclosed quotes `%c'\n"

char	*reverse_quotes_treat(char *str)
{
	printf("--MASK_N_UNMASK_CHARS.C---->[reverse_quotes_treat]\n");
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 3)
		{
			str[i] = '\'';
		}
		else if (str[i] == 2)
		{
			str[i] = '\"';
		}
		i++;
	}
	return (str);
}

void	unmask_character(char *cmd, int nbr, char c)
{
	printf("--MASK_N_UNMASK_CHARS.C---->[unmask_character]\n");
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == nbr)
			cmd[i] = c;
		i++;
	}
}

/*
	Replace characters ' ', '>', '<', '|' and '$' for a non-printable one.
*/
int	mask_all_chars(t_data *data)
{
	printf("\n[--------------------------]\n");
	printf("--MASK_N_UNMASK_CHARS.C---->[mask_all_chars]\n");
	if (mask_character(data->input, ' ', 1))
	{
		g_status_code = SINTAX_ERR;
		return (FAILURE);
	}
	mask_character(data->input, '&', 8);
	mask_character(data->input, '|', 6);
	mask_character(data->input, '>', 4);
	mask_character(data->input, '<', 5);
	mask_dollar(data);
	printf("[------ saida [mask_all_chars]-------------------]\n");
	return (SUCCESS);
}

int	mask_character(char *str, char c, int number)
{
	printf("--MASK_N_UNMASK_CHARS.C---->[mask_character]\n");
	int	i;
	int	sign;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			sign = str[i++];
			while (str[i] != sign && str[i])
			{
				if (str[i] == c)
					str[i] = number;
				i++;
			}
			if (!str[i])
			{
				ft_printf(STDERR, UNCLOSED_QUOTES, sign);
				printf("[------ saida [mask_character]-FAILURE-------------]\n");
				return (FAILURE);
			}
		}
		i++;
	}
	printf("[------ saida [mask_character]-SUCCESS-------------]\n");
	return (SUCCESS);
}
