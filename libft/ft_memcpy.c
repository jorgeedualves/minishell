/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:57:15 by joeduard          #+#    #+#             */
/*   Updated: 2022/05/27 19:57:19 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*src_aux;
	char		*dst_aux;

	if (dst == src)
		return (dst);
	src_aux = (const char *)src;
	dst_aux = (char *)dst;
	while (n > 0)
	{
		*(dst_aux++) = *(src_aux++);
		n--;
	}
	return (dst);
}
