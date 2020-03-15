/*
** EPITECH PROJECT, 2017
** all_check.c
** File description:
** check victory or defeat
*/

#include "main.h"

void check_victory(WINDOW *win, char **map, pos_t *posO, int nbrO)
{
	int vic = 1;

	for (int i = 0; i < nbrO; i++) {
		if (map[posO[i].y][posO[i].x] != 'X')
			vic = 0;
	}
	if (vic == 1)
		close_win(win, "You won !", 5, 0);
}

void check_defeat(WINDOW *win, char **map, int max_line)
{
	int j = 0;
	int i = 0;
	int nbrBox = 0;
	int nbrFail = 0;

	for (j = 0; j < max_line; j++)
		for (i = 0; map[j][i]; i++)
			if (map[j][i] == 'X') {
				nbrBox++;
				if (cant_move_box(map, j, i) == 1)
					nbrFail++;
			}
	if (nbrFail == nbrBox)
		close_win(win, "You lost !", 5, 1);
}

int cant_move_box(char **map, int j, int i)
{
	if ((map[j - 1][i] == '#' && map[j][i - 1] == '#')
	    || (map[j - 1][i] == '#' && map[j][i + 1] == '#')
	    || (map[j + 1][i] == '#' && map[j][i - 1] == '#')
	    || (map[j + 1][i] == '#' && map[j][i + 1] == '#'))
		return (1);
	return (0);
}

void close_win(WINDOW *win, char *str, int len, int status)
{
	clear();
	mvprintw(getmaxy(win) / 2, getmaxx(win) / 2 - len, "%s", str);
	getch();
	refresh();
	endwin();
	exit(status);
}
