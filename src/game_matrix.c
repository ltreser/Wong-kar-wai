/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 02:33:32 by ltreser           #+#    #+#             */
/*   Updated: 2024/05/05 02:52:37 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"
#include <stdlib.h>
#include <time.h>

t_matrix	*init_matrix(int rows, int cols)
{
	t_matrix	*m;

	m = ft_calloc(1, sizeof(m));
	if (!m)
	{
		ft_putstr_fd("ft_calloc failed", 2);
		exit(1);
	}
	m->elements = ft_calloc(rows * cols, sizeof(int));
	if (!m->elements)
	{
		ft_putstr_fd("ft_calloc failed", 2);
		exit(1);
	}
	m->rows = rows;
	m->cols = cols;
	m->username = ft_calloc(1, 21);
	return (m);
}

void	cleanup_matrix(t_matrix *m)
{
	free(m->elements);
	free(m);
}

void	print_matrix(t_matrix *m)
{
	for (int i = 0; i < m->rows; i++)
	{
		for (int j = 0; j < m->cols; j++)
		{
			printw("%d", m->elements[i * m->cols + j]);
			addch(' ');
		}
		addch('\n');
	}
	addch('\n');
	refresh();
}

void	init_rng(void)
{
	srand(time(NULL)); // Initialize seed to current time
}

int	empty_pos(t_matrix *m) //checks if there is an empty space
{
	int i;
	int zeros;

	i = -1;
	zeros = 0;
	while (++i < 16)
		if (!m->elements[i])
			zeros++;
	return (zeros);
}

void	set_random_tile(t_matrix *m)
{
	int	row;
	int	col;
	
	//check if there is an empty position
	if (!empty_pos(m))
		return ;
	// find free position
	while (1)
	{
		row = rand() % m->rows;
		col = rand() % m->cols;
		if (m->elements[row * m->cols + col] == 0)
			break ;
	}
	if (rand() / (double)RAND_MAX < PROB2)
		m->elements[row * m->cols + col] = 2;
	else
		m->elements[row * m->cols + col] = 4;
	return ;
}

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	reverse_matrix(t_matrix *m)
{
	for (int i = 0; i < m->rows; i++)
	{
		for (int j = 0; j < m->cols / 2; j++)
		{
			swap(&m->elements[j + m->cols * i], &m->elements[m->cols - j - 1
				+ m->cols * i]);
		}
	}
}

static void	transpose_matrix(t_matrix *m)
{
	for (int i = 1; i < m->rows; i++)
	{
		for (int j = 0; j < i; j++)
		{
			swap(&m->elements[j + m->cols * i], &m->elements[i + m->cols * j]);
		}
	}
}

static void	compress_row_left(t_matrix *m, int row)
{
	int j, k, l;
	for (j = 1; j < m->cols; j++)
	{
		if (m->elements[j + m->cols * row] == 0)
			continue ;
		for (k = j - 1, l = j; k >= 0; k--)
			if (m->elements[k + m->cols * row] == 0)
				l = k;
		if (l != j)
		{
			swap(&m->elements[j + m->cols * row], &m->elements[l + m->cols
				* row]);
		}
	}
}

static void	merge_row_left(t_matrix *m, int row)
{
	for (int j = 0; j + 1 < m->cols; j++)
	{
		if (m->elements[j + m->cols * row] == m->elements[j + 1 + m->cols
			* row])
		{
			m->elements[j + m->cols * row] *= 2;
			m->elements[j + 1 + m->cols * row] = 0;
		}
	}
}

void	step_left(t_matrix *m)
{
	for (int i = 0; i < m->rows; i++)
	{
		compress_row_left(m, i);
		merge_row_left(m, i);
		compress_row_left(m, i);
	}
}

void	step_right(t_matrix *m)
{
	reverse_matrix(m);
	step_left(m);
	reverse_matrix(m);
}

void	step_up(t_matrix *m)
{
	transpose_matrix(m);
	step_left(m);
	transpose_matrix(m);
}

void	step_down(t_matrix *m)
{
	transpose_matrix(m);
	step_right(m);
	transpose_matrix(m);
}
