/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:48:35 by qsebasti          #+#    #+#             */
/*   Updated: 2017/11/13 12:11:15 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*dest;
	size_t	i;

	i = 0;
	if (!(dest = malloc(size)))
		return (NULL);
	while (i < size)
	{
		((char *)dest)[i] = '\0';
		i++;
	}
	return (dest);
}
