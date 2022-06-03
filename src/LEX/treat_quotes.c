/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:43:55 by joeduard          #+#    #+#             */
/*   Updated: 2022/06/02 02:35:44 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Masks all syntax characters and spaces in quotes,
	splits input into tokens
	(whatever is in quotes is a token) and removes the quotes from them.
	Finally converts the tokens into a new input string.
*/
int	pull_quotes(t_data *data)
{
	printf("\n[--------------------------]\n");
	printf("--TREAT_QUOTES.C---->[pull_quotes]\n");
	if (mask_all_chars(data))
	{
		printf("[------ saida [pull_quotes]-------------------]\n");
		return (FAILURE);
	}
	remove_extra_spaces(data);
	treat_token_strings(data);
	printf("[------ saida [pull_quotes]-------------------]\n");
	return (SUCCESS);
}

/*
	Handles the tokens and merges them back into the input string.
*/
void	treat_token_strings(t_data *data)
{
	printf("--PULL_REDIRECTS.C---->[pull_redirects]\n");
	char	**tokens;
	char	*buf;
	char	*string;
	int		i;

	i = -1;
	string = NULL;
	tokens = ft_split(data->input, ' ');
	while (tokens[++i])
	{
		treat_quotes(tokens[i]);
		no_quotes(tokens[i]);
		if (!string)
			string = tokens_to_string(string, tokens[i]);
		else
		{
			buf = tokens_to_string(string, tokens[i]);
			free(string);
			string = ft_strdup(buf);
			free(buf);
		}
	}
	double_free((void ***)&tokens);
	free(data->input);
	data->input = string;
	printf("[------ saida [pull_redirects]-------------------]\n");
}

/*
	Replaces the inner quotes with 2 or 3.
*/
void	treat_quotes(char *token)
{
	printf("--PULL_REDIRECTS.C---->[treat_quotes]\n");
	int	i;

	i = 0;
	while (token[i])
	{
		if (token[i] == '\'')
		{
			while (token[++i] != '\'')
			{
				if (token[i] == '\"')
					token[i] = 2;
			}
		}
		if (token[i] == '\"')
		{
			while (token[++i] != '\"')
			{
				if (token[i] == '\'')
					token[i] = 3;
			}
		}
		i++;
	}
	printf("[------ saida [treat_quotes]-------------------]\n");
}

/*
	Remove the quotes "3 guarana 31bolo"\0 and then reverse the hidden quotes: 
	'guarana'1bolo\0
*/
void	no_quotes(char *token)
{
	printf("--PULL_REDIRECTS.C---->[no_quotes]\n");
	int		quotes;
	char	*string;
	int		i;
	int		j;

	quotes = 0;
	i = -1;
	while (token[++i])
		if (token[i] == '\'' || token[i] == '\"')
			quotes++;
	if (!quotes)
		return ;
	string = ft_calloc((ft_strlen(token) - quotes + 1), sizeof(char));
	i = -1;
	j = 0;
	while (token[++i])
	{
		if (token[i] == '\'' || token[i] == '\"')
			continue ;
		string[j++] = token[i];
	}
	string = reverse_quotes_treat(string);
	ft_strlcpy(token, string, ft_strlen(string) + 1);
	free(string);
	printf("[------ saida [no_quotes]-------------------]\n");
}

char	*tokens_to_string(char const *s1, char const *s2)
{
	printf("--PULL_REDIRECTS.C---->[tokens_to_string]\n");
	char		*string;
	int			space;
	size_t		i;
	size_t		j;

	i = 0;
	space = ft_strlen(s1) != 0;
	string = malloc((ft_strlen(s1) + ft_strlen(s2) + 1 + space) * sizeof(char));
	if (!string)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			string[i] = s1[i];
			i++;
		}
		string[i++] = ' ';
	}
	j = -1;
	while (s2[++j])
		string[i + j] = s2[j];
	string[i + j] = '\0';
	printf("[------ saida [tokens_to_string]-------------------]\n");
	return (string);
}
