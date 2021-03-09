/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:18:44 by mboy              #+#    #+#             */
/*   Updated: 2021/02/02 11:16:59 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	ssize;
	size_t	dsize;

	i = 0;
	j = 0;
	ssize = ft_strlen(src);
	if (dstsize == 0)
		return (ssize);
	while (dst[i] != '\0')
		i++;
	dsize = i;
	while (i + j < dstsize - 1 && src[j] != '\0')
	{
		dst[i + j] = src[j];
		j++;
	}
	if (j < dstsize)
		dst[i + j] = '\0';
	if (dsize > dstsize)
		return (ssize + dstsize);
	return (ssize + dsize);
}
