/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 20:24:20 by qsebasti          #+#    #+#             */
/*   Updated: 2017/11/27 12:20:51 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	deletelines(char *s, int x)
{
	int	i;

	i = 0;
	if (s[0 * x] == '.' && s[1 * x] == '.' && s[2 * x] == '.' &&
			s[3 * x] == '.')
	{
		if (x == 1)
			x = 4;
		else if (x == 4)
			x = 1;
		while (s[i])
		{
			if (s[i] == '#')
			{
				s[i - x] = '#';
				s[i] = '.';
			}
			i++;
		}
		return (deletelines(s, x));
	}
	return (0);
}

int			ft_copy(t_struct *t, char *s, int nb)
{
	int i;

	i = 0;
	t->j = 0;
	while (s[i] && i < 21)
	{
		if (s[i] == '.' || s[i] == '#')
		{
			t->piece[t->j] = s[i];
			t->j++;
		}
		i++;
	}
	t->piece[16] = '\0';
	deletelines(t->piece, 1) ? 0 : deletelines(t->piece, 4);
	ft_lstback(&(t->lst), t->piece, (unsigned int)nb - 1);
	return (1);
}

int			ft_read(int fd, t_struct *t)
{
	int		ret;
	char	buf[BUF_SIZE + 1];

	if ((ret = read(fd, buf, BUF_SIZE)) == -1)
		return (0);
	else if (ret == 1)
		return (0);
	buf[ret] = '\0';
	if (!ft_checkmap(t, buf))
		return (0);
	return (1);
}
