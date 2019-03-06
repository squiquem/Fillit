/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:37:32 by qsebasti          #+#    #+#             */
/*   Updated: 2017/11/13 13:19:26 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	dizaine(int nb)
{
	int count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		count++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static char	*itoazero(void)
{
	char *dest;

	if (!(dest = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	dest[0] = '0';
	dest[1] = '\0';
	return (dest);
}

static char	*itoaneg(char *s, int n)
{
	int				i;
	unsigned int	nb;

	i = 0;
	nb = -n;
	while (nb > 0)
	{
		s[i] = nb % 10 + '0';
		i++;
		nb = nb / 10;
	}
	s[i] = '-';
	i++;
	s[i] = '\0';
	ft_strrev(s);
	return (s);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		neg;

	i = 0;
	neg = 0;
	if (!(s = (char *)malloc(sizeof(char) * (dizaine(n) + 1))))
		return (NULL);
	if (n < 0)
		return (itoaneg(s, n));
	if (n == 0)
		return (itoazero());
	while (n > 0)
	{
		s[i] = n % 10 + '0';
		i++;
		n = n / 10;
	}
	s[i] = '\0';
	ft_strrev(s);
	return (s);
}
