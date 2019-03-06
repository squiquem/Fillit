/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:37:31 by qsebasti          #+#    #+#             */
/*   Updated: 2017/11/13 16:40:17 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (n == 0)
		return (ft_strlen(src));
	while (dest[i] && i < n)
		i++;
	while (src[j] && (i + j) < (n - 1))
	{
		dest[i + j] = (char)src[j];
		j++;
	}
	if (i < n)
		dest[i + j] = '\0';
	return (i + ft_strlen(src));
}
