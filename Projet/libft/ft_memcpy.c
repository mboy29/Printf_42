/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 09:08:33 by mboy              #+#    #+#             */
/*   Updated: 2021/02/02 11:14:47 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dtmp;
	char	*stmp;

	if (n == 0 || dst == src)
		return (dst);
	i = 0;
	dtmp = (char *)dst;
	stmp = (char *)src;
	while (i < n)
	{
		dtmp[i] = stmp[i];
		i++;
	}
	return (dst);
}
