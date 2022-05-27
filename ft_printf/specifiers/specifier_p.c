/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:18:01 by joeduard          #+#    #+#             */
/*   Updated: 2022/05/27 20:18:01 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*specifier_p(va_list args)
{
	size_t	nbr;
	char	*arg;

	nbr = va_arg(args, size_t);
	arg = ft_hextoa(nbr);
	if (!arg)
		return (NULL);
	return (arg);
}
