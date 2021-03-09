/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:05:10 by mboy              #+#    #+#             */
/*   Updated: 2021/03/04 15:05:23 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_in_unint(char *str, t_flags flags)
{
	int print;

	print = 0;
	if (flags.dot >= 0)
		print += ft_add(flags.dot - 1, ft_strlen(str) - 1, 1);
	print += ft_print(str, ft_strlen(str));
	return (print);
}

static int	ft_unint(char *str, t_flags flags)
{
	int print;

	print = 0;
	if (flags.minus == 1)
		print += ft_in_unint(str, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		print += ft_add(flags.width, 0, 0);
	}
	else
		print += ft_add(flags.width,
		ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		print += ft_in_unint(str, flags);
	return (print);
}

int			ft_print_unint(unsigned int n, t_flags flags)
{
	char	*str;
	int		print;

	print = 0;
	n = (unsigned int)(4294967295 + 1 + n);
	if (flags.dot == 0 && n == 0)
	{
		print += ft_add(flags.width, 0, 0);
		return (print);
	}
	str = ft_u_itoa(n);
	print += ft_unint(str, flags);
	free(str);
	return (print);
}
