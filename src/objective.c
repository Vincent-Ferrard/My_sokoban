/*
** EPITECH PROJECT, 2017
** objective.c
** File description:
** objective
*/

#include "main.h"

int find_nbrO(char **map, int max_line)
{
	int j;
	int i;
	int nbrO = 0;

	for (j = 0; j < max_line; j++)
		for (i = 0; map[j][i]; i++)
			if (map[j][i] == 'O')
				nbrO++;
	return (nbrO);
}

pos_t *init_all_posO(char **map, int max_line)
{
	pos_t *posO;
	int nbrO = 0;
	int i = 0;
	int j = 0;

	for (j = 0; j < max_line; j++)
		for (i = 0; map[j][i]; i++)
			if (map[j][i] == 'O')
				nbrO++;
	posO = malloc(nbrO);
	nbrO = 0;
	for (j = 0; j < max_line; j++)
		for (i = 0; map[j][i]; i++)
			if (map[j][i] == 'O') {
				posO[nbrO].x = i;
				posO[nbrO].y = j;
				nbrO++;
			}
	return (posO);
}

char **display_lost_posO(char **map, pos_t *posO, int nbrO)
{
	for (int i = 0; i < nbrO; i++)
		if (map[posO[i].y][posO[i].x] != 'P'
		    && map[posO[i].y][posO[i].x] != 'X')
			map[posO[i].y][posO[i].x] = 'O';
	return (map);
}
