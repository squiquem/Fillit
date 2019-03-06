/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:53:23 by qsebasti          #+#    #+#             */
/*   Updated: 2017/11/13 16:28:20 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s, const char *to_find)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[i] == '\0')
		return ((char *)s);
	while (s[i])
	{
		j = 0;
		while (s[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return ((char *)s + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
