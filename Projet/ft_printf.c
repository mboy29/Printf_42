/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:05:28 by mboy              #+#    #+#             */
/*   Updated: 2021/03/09 09:46:19 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags		ft_init_flags(void)
{
	t_flags		flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

static int			ft_parse(const char *arg, va_list list)
{
	int			i;
	t_flags		flags;
	int			print;

	i = 0;
	print = 0;
	while (1)
	{
		flags = ft_init_flags();
		if (!arg[i])
			break ;
		else if (arg[i] == '%' && arg[i + 1])
		{
			i = ft_flags(arg, ++i, &flags, list);
			if (ft_is_in_type_list(arg[i]))
				print += ft_conv((char)flags.type, flags, list);
			else if (arg[i])
				print += ft_putchar(arg[i]);
		}
		else if (arg[i] != '%')
			print += ft_putchar(arg[i]);
		i++;
	}
	return (print);
}

int					ft_printf(const char *arg, ...)
{
	const char	*str;
	va_list		list;
	int			print;

	str = ft_strdup(arg);
	print = 0;
	va_start(list, arg);
	print += ft_parse(str, list);
	va_end(list);
	free((char *)str);
	return (print);
}
