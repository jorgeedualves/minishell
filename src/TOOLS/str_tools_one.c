/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tools_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:46:36 by joeduard          #+#    #+#             */
/*   Updated: 2022/06/02 02:40:37 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//count strings in char**
int	ft_str_count(char **str)
{
	printf("\n[--------------------------]\n");
	printf("--STR_TOOLS_ONE.C---->[ft_str_count]\n");
	int		count;

	count = 0;
	if (str)
	{
		while (str[count])
			count++;
	}
	printf("[------ saida [ft_str_count]-------------------]\n");
	return (count);
}

// handled: free old string - add s2 to end of s1
int	ft_strjoin_handled(char **s1, char const *s2)
{
	printf("--STR_TOOLS_ONE.C---->[ft_strjoin_handled]\n");
	size_t	len;
	size_t	k;
	char	*s;

	if (!*s1 || !s2)
	{
		printf("[------ saida [ft_strjoin_handled]-------------------]\n");
		return (FAILURE);
	}
	len = ft_strlen(*s1) + ft_strlen(s2) + 1;
	s = (char *)malloc(len * sizeof(char));
	if (!s)
	{
		printf("[------ saida [ft_strjoin_handled]-------------------]\n");
		return (FAILURE);
	}
		
	k = ft_strlen(*s1);
	ft_strlcpy(s, *s1, k + 1);
	ft_strlcpy(s + k, s2, len - k);
	s[len - 1] = '\0';
	free(*s1);
	*s1 = s;
	printf("[------ saida [ft_strjoin_handled]-------------------]\n");
	return (SUCCESS);
}

/*
	Removes from the str what is between init and end, leaving only the ends.
	eg. str = "Paralelepipedo"
	ft_strcut(&str, 4, 8);
	str ==> "Parapipedo"
*/
void	ft_strcut(char **str, size_t init, size_t end)
{
	printf("--STR_TOOLS_ONE.C---->[ft_strcut]\n");
	char	*first;
	char	*second;

	if (init)
		first = ft_substr(*str, 0, init);
	else
		first = ft_strdup("");
	if (end < ft_strlen(*str))
		second = ft_substr(*str, end, ft_strlen(*str));
	else
		second = ft_strdup("");
	free(*str);
	*str = ft_strjoin(first, second);
	free(first);
	free(second);
	first = NULL;
	second = NULL;
	printf("[------ saida [ft_strcut]-------------------]\n");
}

// remount var from var_name + '=' + var_value
char	*remount_var(char *var_name, char *var_value)
{
	printf("--STR_TOOLS_ONE.C---->[remount_var]\n");
	char	*name;

	name = ft_strdup(var_name);
	ft_strjoin_handled(&name, "=");
	ft_strjoin_handled(&name, var_value);
	printf("[------ saida [remount_var]-------------------]\n");
	return (name);
}

void	move_ptrs_back(char **ptr)
{
	printf("--STR_TOOLS_ONE.C---->[move_ptrs_back]\n");
	int	i;

	i = 0;
	while (ptr[i])
	{
		ptr[i] = ptr[i + 1];
		i++;
	}
	ptr[i] = NULL;
	printf("[------ saida [move_ptrs_back]-------------------]\n");
}
