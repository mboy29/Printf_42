/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:04:57 by mboy              #+#    #+#             */
/*   Updated: 2021/03/04 15:05:15 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_str(char *str, t_flags flags)
{
	int print;

	print = 0;
	if (flags.dot >= 0)
	{
		print += ft_add(flags.dot, ft_strlen(str), 0);
		print += ft_print(str, flags.dot);
	}
	else
	{
		print += ft_print(str, ft_strlen(str));
	}
	return (print);
}

int				ft_print_str(char *str, t_flags flags)
{
	int print;

	print = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		print += ft_str(str, flags);
	if (flags.dot >= 0)
		print += ft_add(flags.width, flags.dot, 0);
	else
		print += ft_add(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		print += ft_str(str, flags);
	return (print);
}
