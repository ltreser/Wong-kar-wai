/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2048.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 02:33:54 by ltreser           #+#    #+#             */
/*   Updated: 2024/05/05 03:57:00 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <ncurses.h>

#ifndef GAME_MATRIX_H
#define GAME_MATRIX_H

#define PROB2 .9 // probability of a random tile being 2

typedef struct s_matrix
{
	int *elements;
	int rows;
	int cols;
	char *username;
} t_matrix;

t_matrix *init_matrix(int rows, int cols);
void cleanup_matrix(t_matrix *m);
void print_matrix(t_matrix *m);
void init_rng();
void set_random_tile(t_matrix *m);
void step_left(t_matrix *m);
void step_right(t_matrix *m);
void step_up(t_matrix *m);
void step_down(t_matrix *m);
int empty_pos(t_matrix *m);
void tui(t_matrix *m);
void    welcome_message(void);
void game_controls(t_matrix *m);
void    init_data(t_matrix *m);	
int enough_space(void);

#endif
