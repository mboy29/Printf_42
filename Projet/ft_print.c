/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:00:42 by mboy              #+#    #+#             */
/*   Updated: 2021/03/04 15:00:51 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print(char *str, int prec)
{
	int print;

	print = 0;
	while (str[print] && print < prec)
		ft_putchar(str[print++]);
	return (print);
}
