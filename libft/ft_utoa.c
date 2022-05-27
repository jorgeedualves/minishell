/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:02:19 by joeduard          #+#    #+#             */
/*   Updated: 2022/05/27 20:02:24 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned int nbr)
{
	unsigned int	temp;
	int				size;
	char			*string;

	temp = nbr;
	size = 0;
	while (temp || !size)
	{
		temp /= 10;
		size++;
	}
	string = (char *)malloc(size + 1);
	string[size--] = 0;
	while (size >= 0)
	{
		string[size--] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (string);
}
