/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:29:53 by qsebasti          #+#    #+#             */
/*   Updated: 2017/11/13 15:22:59 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*pt1;
	unsigned char	*pt2;
	size_t			i;

	pt1 = (unsigned char *)s1;
	pt2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (pt1[i] != pt2[i])
			return (pt1[i] - pt2[i]);
		i++;
	}
	return (0);
}
