/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:34:47 by qsebasti          #+#    #+#             */
/*   Updated: 2017/11/14 20:09:36 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[j])
	{
		if (s[j] != ' ' && s[j] != '\n' && s[j] != '\t')
		{
			j++;
			k = j;
		}
		else
			j++;
	}
	if (k == 0)
		return (ft_strdup(""));
	return (ft_strsub(s, i, k - i));
}
