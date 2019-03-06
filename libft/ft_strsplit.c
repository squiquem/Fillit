/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:41:55 by qsebasti          #+#    #+#             */
/*   Updated: 2017/11/16 15:55:31 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count(char const *s, char c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

static char	**fill_tab(char const *s, char c, char **tab)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			if (!(tab[j] = ft_strnew(i - start + 1)))
				return (NULL);
			tab[j] = ft_strncpy(tab[j], s + start, i - start);
			j++;
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * (count(s, c) + 1))))
		return (NULL);
	if (!(tab = fill_tab(s, c, tab)))
		return (NULL);
	return (tab);
}
