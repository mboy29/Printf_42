/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 09:04:17 by mboy              #+#    #+#             */
/*   Updated: 2021/02/17 09:16:14 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbr_str(char *s, char c)
{
	unsigned int	i;
	unsigned int	nbr;

	i = 0;
	nbr = 0;
	while (s[i])
	{
		if (*s == '\0')
			break ;
		else if (s[i] != c)
		{
			nbr++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (nbr);
}

char		**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			**tab;

	if (!s || !(tab = malloc((sizeof(char*))
		* (ft_nbr_str((char *)s, c) + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
			tab[k++] = ft_strndup(s + j, i - j);
	}
	tab[k] = NULL;
	return (tab);
}
