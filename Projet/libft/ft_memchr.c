/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 09:55:03 by mboy              #+#    #+#             */
/*   Updated: 2021/02/02 11:14:29 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*stmp;

	i = 0;
	stmp = (char *)s;
	while (i < n)
	{
		if (stmp[i] == (char)c)
			return ((void *)&stmp[i]);
		i++;
	}
	return (NULL);
}
