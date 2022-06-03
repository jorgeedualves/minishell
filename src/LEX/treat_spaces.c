/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:44:11 by joeduard          #+#    #+#             */
/*   Updated: 2022/06/02 01:37:12 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_extra_spaces(t_data *data)
{
	printf("\n[--------------------------]\n");
	printf("--TREAT_SPACES.C---->[remove_extra_spaces]\n");
	char	**splitted_spaces;
	int		len;
	int		i;

	splitted_spaces = ft_split(data->input, ' ');
	if (!splitted_spaces)
	{
		printf("[------ saida [emove_extra_spaces]-se a matriz de espaços divididos for nula----]\n");
		exit_minishell(data, FAILURE);
	}
	i = 0;
	len = 0;
	while (splitted_spaces[i])
		len += ft_strlen(splitted_spaces[i++]) + 1;
	free(data->input);
	data->input = (char *)malloc(sizeof(char) * len);
	if (!data->input)
		exit_minishell(data, FAILURE);
	i = 0;
	data->input[0] = 0;
	while (splitted_spaces[i])
	{
		ft_strcat(data->input, splitted_spaces[i]);
		if (splitted_spaces[++i])
			ft_strcat(data->input, " ");
	}
	double_free((void ***)&splitted_spaces);
	printf("[------ saida [remove_extra_spaces]-------------------]\n");
}
