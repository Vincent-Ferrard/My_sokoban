/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main sokoban
*/

#include "main.h"

void game_map(WINDOW *win, char *path_map, int level)
{
	int max_line = find_max_line(path_map) + 1;
	int nbrO = 0;
	char **map;
	pos_t posP;
	pos_t *posO;

	map = init_map(path_map, max_line);
	nbrO = find_nbrO(map, max_line);
	posO = init_all_posO(map, max_line);
	error_map(map, max_line);
	error_win_size(win, map, max_line);
	while (1) {
		call_all_func(win, map, posP, max_line);
		map = display_lost_posO(map, posO, nbrO);
		check_victory(win, map, posO, nbrO, level);
		check_defeat(win, map, max_line);
	}
	refresh();
	endwin();
}

void call_all_func(WINDOW *win, char **map, pos_t posP, int max_line)
{
	clear();
	display_map(map, max_line);
	posP = find_pos_player(map, max_line);
	map = game_key_event(win, map, posP);
}

int main(int ac, char **av)
{
	WINDOW *win;

	help(ac, av);
	if (ac > 1)
		return (84);
	win = initscr();
	attron(A_NORMAL);
	keypad(win, TRUE);
	init_menu(win);
	return (0);
}
