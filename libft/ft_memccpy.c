/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:55:38 by joeduard          #+#    #+#             */
/*   Updated: 2022/05/27 19:55:42 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*src_aux;
	unsigned char	*dst_aux;

	src_aux = (unsigned char *)src;
	dst_aux = (unsigned char *)dst;
	while (n > 0)
	{
		*(dst_aux++) = *src_aux;
		if (*src_aux == (unsigned char)c)
			return (dst_aux);
		src_aux++;
		n--;
	}
	return (0);
}
