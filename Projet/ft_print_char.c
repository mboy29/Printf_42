/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:00:55 by mboy              #+#    #+#             */
/*   Updated: 2021/03/04 15:01:04 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_char(char c, t_flags flags)
{
	int print;

	print = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	print = ft_add(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (print + 1);
}
