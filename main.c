/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:09:49 by qsebasti          #+#    #+#             */
/*   Updated: 2017/11/27 18:16:40 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_error(int a)
{
	if (a == 1)
		ft_putendl("error");
	if (a == 2)
		ft_putendl(USAGE);
	return (0);
}

int		main(int ac, char **av)
{
	int			fd;
	t_struct	t;

	t.lst = NULL;
	if (ac != 2)
		return (ft_error(2));
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (ft_error(1));
	else
	{
		if (!(ft_read(fd, &t)))
		{
			if (t.lst)
				ft_lstclean(&t.lst);
			return (ft_error(1));
		}
		if (!solver(t))
			return (ft_error(1));
		ft_lstclean(&t.lst);
	}
	return (0);
}
