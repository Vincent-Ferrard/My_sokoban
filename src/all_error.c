/*
** EPITECH PROJECT, 2017
** all_error.c
** File description:
** all error
*/

#include "main.h"

void error_win_size(WINDOW *win, char **map, int max_line)
{
	int max_column = 0;

	for (int i = 0; map[0][i]; i++)
		max_column++;
	if (max_line > getmaxy(win) || max_column > getmaxx(win)) {
		mvprintw(getmaxy(win) / 2,
			 (getmaxx(win) / 2) - 10, "Rezise your window !");
		getch();
		refresh();
		endwin();
		exit(84);
	}
}

void error_map(char **map, int max_line)
{
	int i;
	int nbrX = 0;
	int nbrO = 0;
	int nbrP = 0;

	for (int j = 0; j < max_line; j++)
		for (i = 0; map[j][i]; i++)
			switch (map[j][i]) {
			case 'X':
				nbrX++;
				break;
			case 'O':
				nbrO++;
				break;
			case 'P':
				nbrP++;
				break;
			}
	if (error_composant(nbrX, nbrO, nbrP) == 1)
		exit(84);
}

int error_composant(int nbrX, int nbrO, int nbrP)
{
	if (nbrX == 0 || nbrO == 0 || nbrX < nbrO || nbrX > nbrO
	    || nbrP > 1 || nbrP == 0)
		return (1);
	else
		return (0);
}
