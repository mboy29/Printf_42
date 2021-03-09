/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 08:25:37 by mboy              #+#    #+#             */
/*   Updated: 2021/02/02 11:14:22 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*dtmp;
	char	*stmp;

	i = 0;
	dtmp = (char *)dst;
	stmp = (char *)src;
	while (i < n)
	{
		dtmp[i] = stmp[i];
		if (stmp[i] == (char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
