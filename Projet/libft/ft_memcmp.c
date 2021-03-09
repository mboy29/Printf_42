/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 09:00:13 by mboy              #+#    #+#             */
/*   Updated: 2021/02/02 11:14:37 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*tmp1;
	const char	*tmp2;

	i = 0;
	tmp1 = (const char *)s1;
	tmp2 = (const char *)s2;
	if (s1 == s2 || n == 0)
		return (0);
	while (i < (n - 1) && tmp1[i] == tmp2[i])
		i++;
	return ((unsigned char)tmp1[i] - (unsigned char)tmp2[i]);
}
