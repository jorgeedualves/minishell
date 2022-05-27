/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:17:45 by joeduard          #+#    #+#             */
/*   Updated: 2022/05/27 20:17:45 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*specifier_c(va_list args)
{
	char	*arg;

	arg = (char *)malloc(2 * sizeof(char));
	if (!arg)
		return (NULL);
	*arg = va_arg(args, int);
	*(arg + 1) = 0;
	return (arg);
}
