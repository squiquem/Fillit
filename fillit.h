/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:09:18 by qsebasti          #+#    #+#             */
/*   Updated: 2017/11/25 23:19:40 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# define USAGE "usage: fillit source_file"
# define BUF_SIZE 550

typedef struct		s_struct
{
	t_list			*lst;
	char			piece[17];
	int				i;
	int				j;
	int				nb;
	char			*solution;
	int				size;
}					t_struct;

typedef struct		s_tetri
{
	int				case0;
	int				case1;
	int				case2;
	int				case3;
	char			letter;
}					t_tetri;

int					ft_read(int fd, t_struct *t);
int					ft_checkmap(t_struct *t, char *s);
int					ft_copy(t_struct *t, char *s, int nb);
int					ft_error(int a);

int					solver(t_struct tetri);
int					sq_size_min(int n);
char				*make_solution(int size);
t_tetri				*make_tetri_list(t_struct tetri_tab);
int					valid_input(char *solution, int sol_i, t_tetri tetri,
					int size);
void				input_tetri(char *solution, int sol_i, t_tetri tetri,
					int size);
void				remove_tetri(char *solution, int sol_i, t_tetri tetri,
					int size);
t_tetri				tetri_finder(char *tetri);
#endif
