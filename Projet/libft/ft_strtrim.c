/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 10:24:37 by mboy              #+#    #+#             */
/*   Updated: 2021/02/02 11:18:09 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*dst;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_is_set(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_is_set(s1[end], set))
		end--;
	if (!set || ft_strlen(s1) < ft_strlen(set))
		return (ft_strdup(s1));
	if (!(dst = malloc(sizeof(char) * (end - start + 2))))
	{
		free(dst);
		return (NULL);
	}
	i = 0;
	while (start <= end)
		dst[i++] = s1[start++];
	dst[i] = '\0';
	return (dst);
}
