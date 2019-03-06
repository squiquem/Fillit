/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 23:22:11 by squiquem          #+#    #+#             */
/*   Updated: 2017/11/27 16:30:43 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	count_spaces(char *solution)
{
	int	c;

	c = 0;
	while (*solution)
	{
		if (*solution == '.')
			c++;
		solution++;
	}
	return (c);
}

static int	solve(t_struct *t, t_tetri *input, int tet_i, int spaces)
{
	int	sol_i;

	if (count_spaces(t->solution) == spaces)
		return (1);
	sol_i = 0;
	while (t->solution[sol_i])
	{
		if ((valid_input(t->solution, sol_i, input[tet_i], t->size))
				&& t->solution[sol_i] != '\n')
		{
			input_tetri(t->solution, sol_i, input[tet_i], t->size);
			if (solve(t, input, ++tet_i, spaces))
				return (1);
			remove_tetri(t->solution, sol_i, input[--tet_i], t->size);
		}
		sol_i++;
	}
	return (0);
}

int			solver(t_struct tetri)
{
	int		i;
	int		solved;
	t_tetri	*input;
	int		spaces;

	input = make_tetri_list(tetri);
	solved = 0;
	i = 0;
	while (!solved)
	{
		tetri.size = sq_size_min(tetri.nb) + i;
		spaces = (tetri.size * tetri.size) - (4 * tetri.nb);
		if (!(tetri.solution = make_solution(tetri.size)))
			return (0);
		if (solve(&tetri, input, 0, spaces))
		{
			solved = 1;
			ft_putstr(tetri.solution);
		}
		free(tetri.solution);
		i++;
	}
	free(input);
	return (1);
}
