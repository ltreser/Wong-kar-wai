/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* 
                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 02:34:20 by ltreser           #+#    #+#             */
/*   Updated: 2024/05/04 23:20:06 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

#define ROWS 4
#define COLUMS 4

void	init_data(t_matrix *m)
{
	init_rng();
	set_random_tile(m);
	set_random_tile(m);
	initscr();
	curs_set(0);
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
}

void game_controls(t_matrix *m)
{
	int c;

	print_matrix(m);	
	while ((c = getch()) != 27 && empty_pos(m))
	{
		if (!enough_space())
			print_matrix(m);
		if (c == KEY_RESIZE)
			continue ;
		clear ();
		if (c == KEY_DOWN)
			step_down(m);
		else if (c == KEY_LEFT)
			step_left(m);
		else if (c == KEY_RIGHT)
			step_right(m);
		else if (c == KEY_UP)
			step_up(m);
		else
		{
			printw("wrong key\n");
			refresh();
			print_matrix(m);
			continue ;
		}
		set_random_tile(m);
		print_matrix(m);
	}
}

int enough_space(void)
{
	if (!(LINES < 4))
		return (1);
	while (LINES < 4)
    {
        mvprintw(0, 0, "Please increase window size");
        refresh();
        napms(500);
        clear();
    }
	return (0);
}

void	welcome_message(void) //print welcome message
{
	clear();
	while (LINES < 11)
	{
		mvprintw(0, 0, "Please increase window size");
		refresh();
		napms(500);
		clear();
	}
	int row;
	int start_col;
	int current_col;
	int i;
	char str[] = "~ Hello there! This is the game 2048, implemented by Phillip and Lima in a Rush weekend.\n\nFun fact:\n\nDid you know the Game was created by Gabriele Cirulli one weekend as a clone of another game called 1024? ~";

	i = 0;
	row = (LINES / 2) - 10; //use macro of ncurses to get dimensions, center
	start_col = (COLS - 30) / 2;
	current_col = start_col; //reset so its left-bound text
	while (str[i])
	{
		if (LINES < 11 || LINES < row + 10)
			return (welcome_message());
		if (str[i] == '\n' || ((current_col - start_col) > 30 && str[i] == ' ')) //not print too much at a time
		{
			row++;
			current_col = start_col;
			i++;
			continue ;
		}
		mvaddch(row, current_col, str[i]);
		refresh();
		napms(50); //add cute retro look
		i++;
		current_col++;
	}
	napms(1500);
	clear();
	return ;
}

void	get_username(t_matrix *m)
{
	int i;
	int c;

	i = 0;
	mvprintw((LINES / 2), ((COLS / 2) - 30), "Please enter a username:");
	while ((c = getch()) != 10)
	{
		if (!enough_space())
		{
			clear();
            mvprintw((LINES / 2), ((COLS / 2) - 30), "Please enter a username:");
            mvprintw(((LINES / 2) + 2), ((COLS / 2) - 30), "%s_", m->username);
            refresh();
		}
		if (c == KEY_BACKSPACE)
		{
			m->username[i] = 0;
			clear();
			mvprintw((LINES / 2), ((COLS / 2) - 30), "Please enter a username:");
			mvprintw(((LINES / 2) + 2), ((COLS / 2) - 30), "%s_", m->username);		
			refresh();
			if (i)
				i--;
			continue ;	
		}
		else if (ft_isalnum(c) && i < 20)
		{
			m->username[i] = (char)c;
		i++;
		}
		else 
			continue ;
	mvprintw(((LINES / 2) + 2), ((COLS / 2) - 30), "%s_", m->username);	
	}
	clear();
	mvprintw((LINES / 2), ((COLS / 2) - 30), "hello, %s!", m->username);
	refresh();
	napms(1500);
	clear();
	return ;
}

void tui(t_matrix *m)
{
	//welcome_message();
	get_username(m);
	//menu(m);
	game_controls(m);
	endwin();
}

int	main(void)
{
    t_matrix	*m;

	m = init_matrix(ROWS, COLUMS);
	init_data(m);
	tui(m);
	cleanup_matrix(m);
	return (0);
}
