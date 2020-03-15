/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main sokoban
*/

#include "main.h"

void game_map(char *path_map)
{
	int max_line = find_max_line(path_map) + 1;
	int nbrO = 0;
	WINDOW *win;
	char **map;
	pos_t posP;
	pos_t *posO;

	map = init_all(path_map, max_line);
	nbrO = find_nbrO(map, max_line);
	posO = init_all_posO(map, max_line);
	win = initscr();
	error_win_size(win, map, max_line);
	attron(A_NORMAL);
	keypad(win, TRUE);
	while (1) {
		call_all_func(map, posP, max_line);
		map = display_lost_posO(map, posO, nbrO);
		check_victory(win, map, posO, nbrO);
		check_defeat(win, map, max_line);
	}
}

char **init_all(char *path_map, int max_line)
{
	char **map;

	map = init_map(path_map, max_line);
	error_map(map, max_line);
	return (map);
}

void call_all_func(char **map, pos_t posP, int max_line)
{
	clear();
	display_map(map, max_line);
	posP = find_pos_player(map, max_line);
	map = game_key_event(map, posP);
}

int main(int ac, char **av)
{
	if (ac < 2 || ac > 2)
		return (84);
	help(ac, av);
	game_map(av[1]);
	return (0);
}
