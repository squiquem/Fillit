/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 20:53:29 by qsebasti          #+#    #+#             */
/*   Updated: 2017/11/27 18:43:22 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_near(char *s)
{
	int		nb;
	int		i;
	int		nbhtag;

	nb = 0;
	i = 0;
	nbhtag = 0;
	while (i < 20)
	{
		s[i] == '#' ? nbhtag++ : nbhtag + 0;
		if (s[i] == '#' && s[i - 1] && s[i - 1] == '#')
			nb++;
		if (s[i] == '#' && s[i + 1] && s[i + 1] == '#')
			nb++;
		if (s[i] == '#' && s[i + 5] && s[i + 5] == '#' && i + 5 < 20)
			nb++;
		if (s[i] == '#' && s[i - 5] && s[i - 5] == '#' && i - 5 > -1)
			nb++;
		i++;
	}
	if ((nb != 8 && nb != 6) || nbhtag != 4 || s[4] != '\n' || s[9] != '\n' ||
			s[14] != '\n' || s[19] != '\n')
		return (0);
	return (1);
}

int			ft_checkmap(t_struct *t, char *s)
{
	int start;

	t->nb = 1;
	t->i = 0;
	while (s[t->i])
	{
		start = t->i;
		while (t->i < start + 21 && s[t->i])
		{
			if (s[t->i] == '\n' && s[t->i + 1] == '\n' && s[start + 20] == '\n'
					&& (s[t->i + 2] == '.' || s[t->i + 2] == '#'))
				t->nb++;
			if (s[t->i] != '#' && s[t->i] != '.' && s[t->i] != '\n')
				return (0);
			t->i++;
		}
		if (!ft_near(s + start) || !ft_copy(t, s + start, t->nb - 1))
			return (0);
	}
	if (t->i != (20 * t->nb + t->nb - 1) || t->nb > 26)
		return (0);
	return (1);
}
