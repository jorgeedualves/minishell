/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:01:39 by joeduard          #+#    #+#             */
/*   Updated: 2022/05/27 20:01:42 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	substr_len;
	char	*substr;

	i = 0;
	if (s == 0)
		return (0);
	substr_len = ft_strlen(s);
	if (len > substr_len - start)
		substr = (char *)malloc((substr_len - start + 1) * sizeof(char));
	else if (substr_len < len)
		substr = (char *)malloc((substr_len + 1) * sizeof(char));
	else
		substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == 0)
		return (0);
	while (i < len && (start + i) < substr_len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
