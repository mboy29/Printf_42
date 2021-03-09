/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:01:42 by mboy              #+#    #+#             */
/*   Updated: 2021/03/04 15:04:18 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_in_int(char *str, int n, t_flags flags)
{
	int print;

	print = 0;
	if (flags.star != 1200 && n < 0 && flags.dot >= 0)
		ft_putchar('-');
	if (flags.star == 1200 && flags.zero == 1 && flags.dot == -1)
		print--;
	if (flags.star == 1200 && flags.dot > 0
			&& flags.width > 0 && flags.minus == 0)
		print += ft_putchar(' ');
	if (flags.star == 1200 && flags.dot >= 0)
		print--;
	if (flags.star == 1200 && flags.zero == 1 && flags.dot <= -2)
		print--;
	if (flags.dot >= 0)
		print += ft_add(flags.dot - 1, ft_strlen(str) - 1, 1);
	print += ft_print(str, ft_strlen(str));
	return (print);
}

static int	ft_int(char *str, int n, t_flags flags)
{
	int print;

	print = 0;
	if (n < 0 && flags.star == 1 && flags.zero == 1 && flags.dot <= -2)
		ft_putchar('-');
	if (flags.minus == 1)
		print += ft_in_int(str, n, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		print += ft_add(flags.width, 0, 0);
	}
	else if (flags.minus == 1)
		print += ft_add(flags.width, ft_strlen(str), 0);
	else if (flags.minus == 0)
		print += ft_add(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		print += ft_in_int(str, n, flags);
	return (print);
}

int			ft_print_int(int n, t_flags flags)
{
	char	*str;
	int		save_n;
	int		print;

	save_n = n;
	print = 0;
	if (flags.dot == 0 && n == 0)
	{
		print += ft_add(flags.width, 0, 0);
		return (print);
	}
	if (n < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		flags.star = (n == -2147483648 ? 1200 : flags.star);
		if (flags.star != 1200 && flags.zero == 1 && flags.dot == -1)
			ft_print("-", 1);
		n *= -1;
		flags.zero = 1;
		flags.width--;
		print++;
	}
	str = ft_itoa(n);
	print += ft_int(str, save_n, flags);
	free(str);
	return (print);
}
