/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:59:23 by joeduard          #+#    #+#             */
/*   Updated: 2022/05/27 19:59:28 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		size;
	char	*new;

	i = 0;
	size = ft_strlen(s1);
	new = (char *)ft_calloc(size + 1, sizeof(char));
	if (new != NULL)
	{
		while (i < size)
		{
			new[i] = s1[i];
			i++;
		}
	}
	return (new);
}
