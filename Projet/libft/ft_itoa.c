/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:00:23 by mboy              #+#    #+#             */
/*   Updated: 2021/02/05 08:09:12 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_strcpy(int n, char *src)
{
	int		i;
	char	*dst;

	i = 0;
	if (n == -2147483648)
		if (!(dst = malloc(sizeof(char) * 12)))
			return (NULL);
	if (n == 2147483647)
		if (!(dst = malloc(sizeof(char) * 11)))
			return (NULL);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	*ft_limits(int n)
{
	if (n == 2147483647)
		return (ft_strcpy(n, "2147483647"));
	return (ft_strcpy(n, "-2147483648"));
}

char		*ft_itoa(int n)
{
	int		nb;
	int		len;
	char	*str;

	if (n == -2147483648 || n == 2147483647)
		return (ft_limits(n));
	nb = (n < 0 ? n * -1 : n);
	len = ft_len(nb);
	if (n < 0)
		len++;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (nb > 0)
	{
		str[--len] = (nb % 10) + 48;
		nb = nb / 10;
	}
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	return (str);
}
