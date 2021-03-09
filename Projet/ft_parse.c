/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:00:13 by mboy              #+#    #+#             */
/*   Updated: 2021/03/04 15:00:38 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_in_type_list(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int		ft_is_in_flags_list(int c)
{
	return ((c == '-') || (c == ' ') || (c == '0') || (c == '.') || (c == '*'));
}

int		ft_flags(const char *arg, int i, t_flags *flags, va_list list)
{
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) && !ft_is_in_type_list(arg[i])
		&& !ft_is_in_flags_list(arg[i]))
			break ;
		if (arg[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (arg[i] == '.')
			i = ft_flags_dot(arg, i, flags, list);
		if (arg[i] == '-')
			*flags = ft_flags_minus(*flags);
		if (arg[i] == '*')
			*flags = ft_flags_star(list, *flags);
		if (ft_isdigit(arg[i]))
			*flags = ft_flags_width(arg[i], *flags);
		if (ft_is_in_type_list(arg[i]))
		{
			flags->type = arg[i];
			break ;
		}
		i++;
	}
	return (i);
}

int		ft_conv(int c, t_flags flags, va_list list)
{
	int print;

	print = 0;
	if (c == 'c')
		print = ft_print_char(va_arg(list, int), flags);
	else if (c == 's')
		print = ft_print_str(va_arg(list, char *), flags);
	else if (c == 'p')
		print = ft_print_ptr(va_arg(list, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		print = ft_print_int(va_arg(list, int), flags);
	else if (c == 'u')
		print += ft_print_unint((unsigned int)va_arg(list, unsigned int),
		flags);
	else if (c == 'x')
		print += ft_print_hex(va_arg(list, unsigned int), 1, flags);
	else if (c == 'X')
		print += ft_print_hex(va_arg(list, unsigned int), 0, flags);
	else if (c == '%')
		print += ft_print_pct(flags);
	return (print);
}
