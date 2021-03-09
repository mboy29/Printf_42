/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:04:42 by mboy              #+#    #+#             */
/*   Updated: 2021/03/04 15:04:50 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr(char *ptr, t_flags flags)
{
	int print;

	print = 0;
	print += ft_print("0x", 2);
	if (flags.dot >= 0)
	{
		print += ft_add(flags.dot, ft_strlen(ptr), 1);
		print += ft_print(ptr, flags.dot);
	}
	else
		print += ft_print(ptr, ft_strlen(ptr));
	return (print);
}

int			ft_print_ptr(unsigned long long n, t_flags flags)
{
	char	*ptr;
	int		print;

	print = 0;
	if (n == 0 && flags.dot == 0)
	{
		print += ft_print("0x", 2);
		return (print += ft_add(flags.width, 0, 1));
	}
	ptr = ft_base(n, 16);
	ptr = ft_str_tolower(ptr);
	if ((size_t)flags.dot < ft_strlen(ptr))
		flags.dot = ft_strlen(ptr);
	if (flags.minus == 1)
		print += ft_ptr(ptr, flags);
	print += ft_add(flags.width, ft_strlen(ptr) + 2, 0);
	if (flags.minus == 0)
		print += ft_ptr(ptr, flags);
	free(ptr);
	return (print);
}
