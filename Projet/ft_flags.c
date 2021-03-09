/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:56:49 by mboy              #+#    #+#             */
/*   Updated: 2021/03/04 15:00:05 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_flags_width(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}

t_flags	ft_flags_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags	ft_flags_star(va_list list, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(list, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
	}
	return (flags);
}

int		ft_flags_dot(const char *arg, int start, t_flags *flags, va_list list)
{
	int i;

	i = start;
	i++;
	if (arg[i] == '*')
	{
		flags->dot = va_arg(list, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(arg[i]))
			flags->dot = (flags->dot * 10) + (arg[i++] - '0');
	}
	return (i);
}
