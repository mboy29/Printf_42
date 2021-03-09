/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:00:34 by mboy              #+#    #+#             */
/*   Updated: 2021/02/02 11:18:20 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*stmp;

	i = 0;
	if (!s || len <= 0 || start >= ft_strlen(s))
		return (ft_strdup(""));
	stmp = malloc(sizeof(char) * (len + 1));
	if (!stmp)
		return (NULL);
	while (len)
	{
		stmp[i] = s[start + i];
		i++;
		len--;
	}
	stmp[i] = '\0';
	return (stmp);
}
