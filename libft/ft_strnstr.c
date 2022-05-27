/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:01:11 by joeduard          #+#    #+#             */
/*   Updated: 2022/05/27 20:01:15 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_size;

	len_size = ft_strlen(little);
	if (len_size == 0)
		return ((char *)big);
	if (len_size > ft_strlen(big))
		return (NULL);
	while (*big && len)
	{
		if (len_size > ft_strlen(big) || len < len_size)
			return (NULL);
		if (ft_strncmp(big, little, len_size) == 0 && len >= len_size)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
