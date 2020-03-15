/*
** EPITECH PROJECT, 2017
** all_check.c
** File description:
** check victory or defeat
*/

#include "main.h"

void check_victory(WINDOW *win, char **map, pos_t *posO, int nbrO, int level)
{
	int vic = 1;

	for (int i = 0; i < nbrO; i++) {
		if (map[posO[i].y][posO[i].x] != 'X')
			vic = 0;
	}
	if (vic == 1) {
		free(map);
		refresh();
		close_win(win, "You won !", 5);
		put_score(level);
		init_level(win);
	}
}

void put_score(int level)
{
	int fd;
	char c;

	fd = open("map/score", O_RDONLY);
	read(fd, &c, 1);
	if (c < level + '0') {
		close(fd);
		c = level + '0';
		fd = open("map/score", O_WRONLY);
		write(fd, &c, 1);
	}
	close(fd);
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
	if (nbrFail == nbrBox) {
		close_win(win, "You lost !", 5);
		init_level(win);
	}
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

void close_win(WINDOW *win, char *str, int len)
{
	clear();
	mvprintw(getmaxy(win) / 2, getmaxx(win) / 2 - len, "%s", str);
	getch();
}
