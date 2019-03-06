/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 23:22:37 by squiquem          #+#    #+#             */
/*   Updated: 2017/11/25 23:26:19 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	t_tetri_creation(int a, int b, int c, int d)
{
	t_tetri	res;

	res.case0 = a;
	res.case1 = b;
	res.case2 = c;
	res.case3 = d;
	res.letter = '#';
	return (res);
}

void	tetri_index(int tetrindex[4], char *tetri)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tetri[j])
	{
		if (tetri[j] != '.')
		{
			tetrindex[i] = j;
			i++;
		}
		j++;
	}
}

void	models(t_tetri mod[19])
{
	mod[0] = t_tetri_creation(0, 1, 4, 5);
	mod[1] = t_tetri_creation(0, 1, 2, 3);
	mod[2] = t_tetri_creation(0, 4, 8, 12);
	mod[3] = t_tetri_creation(0, 1, 5, 6);
	mod[4] = t_tetri_creation(1, 4, 5, 8);
	mod[5] = t_tetri_creation(1, 2, 4, 5);
	mod[6] = t_tetri_creation(0, 4, 5, 9);
	mod[7] = t_tetri_creation(0, 4, 5, 6);
	mod[8] = t_tetri_creation(1, 5, 8, 9);
	mod[9] = t_tetri_creation(0, 1, 2, 6);
	mod[10] = t_tetri_creation(0, 1, 4, 8);
	mod[11] = t_tetri_creation(0, 4, 8, 9);
	mod[12] = t_tetri_creation(2, 4, 5, 6);
	mod[13] = t_tetri_creation(0, 1, 5, 9);
	mod[14] = t_tetri_creation(0, 1, 2, 4);
	mod[15] = t_tetri_creation(0, 4, 5, 8);
	mod[16] = t_tetri_creation(1, 4, 5, 9);
	mod[17] = t_tetri_creation(1, 4, 5, 6);
	mod[18] = t_tetri_creation(0, 1, 2, 5);
}

t_tetri	tetri_finder(char *tetri)
{
	int		tindex[4];
	t_tetri	mod[19];
	int		i;

	i = 0;
	tetri_index(tindex, tetri);
	models(mod);
	while (i < 19)
	{
		if (tindex[1] - tindex[0] == mod[i].case1 - mod[i].case0 &&
				tindex[2] - tindex[0] == mod[i].case2 - mod[i].case0 &&
				tindex[3] - tindex[0] == mod[i].case3 - mod[i].case0)
			return (mod[i]);
		i++;
	}
	return (mod[i]);
}
