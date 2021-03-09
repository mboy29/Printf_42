/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:56:34 by mboy              #+#    #+#             */
/*   Updated: 2021/03/04 14:59:26 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*treat_base(unsigned long long n, int base,
char *rtn, int i)
{
	while (n != 0)
	{
		if ((n % base) < 10)
			rtn[i - 1] = (n % base) + 48;
		else
			rtn[i - 1] = (n % base) + 55;
		n /= base;
		i--;
	}
	return (rtn);
}

char		*ft_base(unsigned long long n, int base)
{
	char				*rtn;
	unsigned long long	n_save;
	int					i;

	rtn = 0;
	i = 0;
	n_save = n;
	if (n == 0)
		return (ft_strdup("0"));
	while (n != 0)
	{
		n /= base;
		i++;
	}
	if (!(rtn = malloc(sizeof(char) * (i + 1))))
		return (0);
	rtn[i] = '\0';
	rtn = treat_base(n_save, base, rtn, i);
	return (rtn);
}
