/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:27:51 by qsebasti          #+#    #+#             */
/*   Updated: 2017/11/13 12:13:43 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*ptr1;
	char	*ptr2;
	size_t	i;

	ptr1 = s1;
	ptr2 = (char *)s2;
	i = 0;
	if (s2 == s1)
		return (s1);
	else if (s2 < s1)
		while (n > 0)
		{
			ptr1[n - 1] = ptr2[n - 1];
			n--;
		}
	else if (s2 > s1)
		while (i < n)
		{
			ptr1[i] = ptr2[i];
			i++;
		}
	return (s1);
}
