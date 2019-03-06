/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 23:22:29 by squiquem          #+#    #+#             */
/*   Updated: 2017/11/27 12:20:03 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		sq_size_min(int n)
{
	int	i;

	i = 1;
	while (i * i < 4 * n)
		i++;
	return (i);
}

char	*make_solution(int size)
{
	char	*solution;
	int		i;

	if (!(solution = (char *)malloc(sizeof(char) *
					(size * (size + 1) + 1))))
		return (NULL);
	i = 0;
	while (i < size * (size + 1))
	{
		if (((i + 1) % (size + 1)) == 0)
			solution[i] = '\n';
		else
			solution[i] = '.';
		i++;
	}
	solution[i] = '\0';
	return (solution);
}

t_tetri	*make_tetri_list(t_struct tetri_tab)
{
	int		i;
	t_tetri	*input;

	i = 0;
	if (!(input = (t_tetri *)malloc(sizeof(t_tetri) * tetri_tab.nb)))
		return (NULL);
	while (i < tetri_tab.nb)
	{
		input[i] = tetri_finder(tetri_tab.lst->content);
		input[i].letter = i + 'A';
		tetri_tab.lst = tetri_tab.lst->next;
		i++;
	}
	return (input);
}
