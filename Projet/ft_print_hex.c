/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:01:10 by mboy              #+#    #+#             */
/*   Updated: 2021/03/04 15:01:25 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_in_hex(char *hex, t_flags flags)
{
	int print;

	print = 0;
	if (flags.dot >= 0)
		print += ft_add(flags.dot - 1, ft_strlen(hex) - 1, 1);
	print += ft_print(hex, ft_strlen(hex));
	return (print);
}

static int		ft_hex(char *hex, t_flags flags)
{
	int print;

	print = 0;
	if (flags.minus == 1)
		print += ft_in_hex(hex, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hex))
		flags.dot = ft_strlen(hex);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		print += ft_add(flags.width, 0, 0);
	}
	else
		print += ft_add(flags.width,
		ft_strlen(hex), flags.zero);
	if (flags.minus == 0)
		print += ft_in_hex(hex, flags);
	return (print);
}

int				ft_print_hex(unsigned int n, int lower, t_flags flags)
{
	char	*hex;
	int		print;

	print = 0;
	n = (unsigned int)(4294967295 + 1 + n);
	if (flags.dot == 0 && n == 0)
	{
		print += ft_add(flags.width, 0, 0);
		return (print);
	}
	hex = ft_base((unsigned long long)n, 16);
	if (lower == 1)
		hex = ft_str_tolower(hex);
	print += ft_hex(hex, flags);
	free(hex);
	return (print);
}
