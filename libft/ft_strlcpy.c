/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:00:22 by joeduard          #+#    #+#             */
/*   Updated: 2022/05/27 20:00:25 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*src_aux;

	if (!dst || !src)
		return (0);
	src_aux = (const char *)src;
	if (size > 0)
	{
		while (size > 1 && *src_aux)
		{
			*(dst++) = *(src_aux++);
			size--;
		}
		*dst = '\0';
	}
	return (ft_strlen(src));
}
