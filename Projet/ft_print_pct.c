/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:04:23 by mboy              #+#    #+#             */
/*   Updated: 2021/03/04 15:04:34 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_pct(t_flags flags)
{
	int print;

	print = 0;
	if (flags.minus == 1)
		print += ft_print("%", 1);
	print += ft_add(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		print += ft_print("%", 1);
	return (print);
}
