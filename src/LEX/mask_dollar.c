/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask_dollar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:49:28 by vlima-nu          #+#    #+#             */
/*   Updated: 2022/06/02 02:47:18 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_dollar_sign(char c);
static int	is_quotes_or_space(char c);
static void	cut_dollar(t_data *data, int i);

void	mask_dollar(t_data *data)
{
	printf("\n[--------------------------]\n");
	printf("--MASK_DOLLAR.C---->[mask_dollar]\n");
	int	i;
	int	sign;

	i = -1;
	while (data->input[++i])
	{
		if (is_dollar_sign(data->input[i]))
			cut_dollar(data, i);
		if (data->input[i] == '\'' || data->input[i] == '\"')
		{
			sign = data->input[i++];
			while (data->input[i] != sign && data->input[i])
			{
				if ((is_dollar_sign(data->input[i]) && \
				(sign == '\'' || is_quotes_or_space(data->input[i + 1]))))
					data->input[i] = 7;
				i++;
			}
		}
	}
	printf("[------ saida [mask_dollar]-------------------]\n");
}

static void	cut_dollar(t_data *data, int i)
{
	printf("--MASK_DOLLAR.C---->[cut_dollar]\n");
	int		j;

	if (!data->input[i + 1] || data->input[i + 1] == 1 || \
	ft_strchr("+=", data->input[i + 1]))
		data->input[i] = 7;
	else if (ft_strchr("\'\"@!*123456789", data->input[i + 1]))
	{
		j = (ft_strchr("@!*123456789", data->input[i + 1]) != 0);
		ft_strcut(&data->input, i, i + j + 1);
		i--;
	}
	printf("[------ saida [cut_dollar]-------------------]\n");
}

static int	is_dollar_sign(char c)
{
	printf("--MASK_DOLLAR.C---->[is_dollar]\n");
	printf("[------ saida [is_dollar]-------------------]\n");
	return (c == '$');
}

static int	is_quotes_or_space(char c)
{
	printf("--MASK_DOLLAR.C---->[is_ quotes_or_space]\n");
	printf("[------ saida [is_ quotes_or_space]-------------------]\n");
	return (ft_strchr("\'\"", c) || c == 1);
}
