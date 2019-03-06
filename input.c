/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 23:22:43 by squiquem          #+#    #+#             */
/*   Updated: 2017/11/27 16:18:29 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		sol_case(int sol_i, int cas, int size)
{
	int	i;

	i = (cas / 4) * (size + 1) + cas % 4 + sol_i;
	return (i);
}

int		valid_input(char *solution, int sol_i, t_tetri tetri, int size)
{
	int	i;
	int	t[8];

	i = 0;
	t[0] = sol_case(sol_i, tetri.case0, size);
	t[1] = sol_case(sol_i, tetri.case1, size);
	t[2] = sol_case(sol_i, tetri.case2, size);
	t[3] = sol_case(sol_i, tetri.case3, size);
	t[4] = tetri.case0;
	t[5] = tetri.case1;
	t[6] = tetri.case2;
	t[7] = tetri.case3;
	while (i < 4)
	{
		if (t[i] >= (size * (size + 1))
			|| solution[t[i]] != '.'
			|| sol_i % (size + 1) + t[i + 4] % 4 >= size
			|| sol_i / (size + 1) + t[i + 4] / 4 >= size)
			return (0);
		i++;
	}
	return (1);
}

void	input_tetri(char *solution, int sol_i, t_tetri tetri, int size)
{
	solution[sol_case(sol_i, tetri.case0, size)] = tetri.letter;
	solution[sol_case(sol_i, tetri.case1, size)] = tetri.letter;
	solution[sol_case(sol_i, tetri.case2, size)] = tetri.letter;
	solution[sol_case(sol_i, tetri.case3, size)] = tetri.letter;
}

void	remove_tetri(char *solution, int sol_i, t_tetri tetri, int size)
{
	solution[sol_case(sol_i, tetri.case0, size)] = '.';
	solution[sol_case(sol_i, tetri.case1, size)] = '.';
	solution[sol_case(sol_i, tetri.case2, size)] = '.';
	solution[sol_case(sol_i, tetri.case3, size)] = '.';
}
