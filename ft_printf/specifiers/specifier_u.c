/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:18:19 by joeduard          #+#    #+#             */
/*   Updated: 2022/05/27 20:18:19 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*specifier_u(va_list args, t_params p)
{
	unsigned int	nbr;
	char			*arg;

	nbr = va_arg(args, unsigned int);
	if (!nbr && !p.precision && p.precision_c)
		return (ft_strdup(""));
	arg = ft_utoa(nbr);
	if (!arg)
		return (NULL);
	return (arg);
}
