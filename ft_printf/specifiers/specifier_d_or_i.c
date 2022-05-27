/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_d_or_i.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:17:53 by joeduard          #+#    #+#             */
/*   Updated: 2022/05/27 20:17:53 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*specifier_d_or_i(va_list args, t_params params)
{
	int		nbr;
	char	*arg;

	nbr = va_arg(args, int);
	if (!params.precision && !nbr && params.precision_c)
		return (ft_strdup(""));
	arg = ft_itoa(nbr);
	if (!arg)
		return (NULL);
	return (arg);
}
