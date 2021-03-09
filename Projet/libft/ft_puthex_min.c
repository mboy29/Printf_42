/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_minhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 09:29:58 by mboy              #+#    #+#             */
/*   Updated: 2021/03/04 15:30:48 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_minhex(char *hex, int i)
{
	write(1, "\0", 1);
	while (--i >= 0)
	{
		hex[i] = ft_tolower(hex[i]);
		write(1, &hex[i], 1);
	}
}

static int	ft_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static int	ft_zero(unsigned int n)
{
	if (n == 0)
		write(1, "0", 1);
	return (1);
}

int			ft_puthex_min(unsigned int n)
{
	long	quotient;
	long	left;
	char	*hex;
	int		i;

	i = 0;
	if (n == 0)
		return (ft_zero(n));
	if (!(hex = malloc(sizeof(char) * (ft_len(n) + 1))))
		return (0);
	quotient = n;
	while (quotient > 0)
	{
		left = quotient % 16;
		if (left < 10)
			hex[i++] = left + 48;
		else
			hex[i++] = left + 55;
		quotient = quotient / 16;
	}
	hex[i] = '\0';
	ft_minhex(hex, ft_len(n));
	return (ft_len(n));
}
