/*
** EPITECH PROJECT, 2017
** player.c
** File description:
** player functions
*/

#include "main.h"

pos_t find_pos_player(char **map, int max_line)
{
	pos_t posP;
	int j = 0;
	int i = 0;

	for (j = 0; j < max_line; j++)
		for (i = 0; map[j][i]; i++)
			if (map[j][i] == 'P') {
				posP.x = i;
				posP.y = j;
			}
	return (posP);
}

char **move_player(char **map, pos_t posP, int y, int x)
{
	if (map[y][x] == 'X') {
		map = boxes_conditions(map, posP, y, x);
	}
	else if (map[y][x] != '#' && map[y][x] != 'X') {
		map[y][x] = 'P';
		map[posP.y][posP.x] = ' ';
	}
	return (map);
}

char **boxes_conditions(char **map, pos_t posP, int y, int x)
{
	if (map[y][x] == 'X') {
		if (posP.y + 1 == y && map[y + 1][x] != 'X'
		    && map[y + 1][x] != '#')
			map = move_box(map, posP, 1);
		else if (posP.y - 1 == y && map[y - 1][x] != 'X'
		    && map[y - 1][x] != '#')
			map = move_box(map, posP, 2);
		else if (posP.x + 1 == x && map[y][x + 1] != 'X'
		    && map[y][x + 1] != '#')
			map = move_box(map, posP, 3);
		else if (posP.x - 1 == x && map[y][x - 1] != 'X'
		    && map[y][x - 1] != '#')
			map = move_box(map, posP, 4);
	}
	return (map);
}

char **move_box(char **map, pos_t posP, int key_value)
{
	switch (key_value) {
	case 1:
		map[posP.y + 2][posP.x] = 'X';
		map[posP.y + 1][posP.x] = 'P';
		break;
	case 2:
		map[posP.y - 2][posP.x] = 'X';
		map[posP.y - 1][posP.x] = 'P';
		break;
	case 3:
		map[posP.y][posP.x + 2] = 'X';
		map[posP.y][posP.x + 1] = 'P';
		break;
	case 4:
		map[posP.y][posP.x - 2] = 'X';
		map[posP.y][posP.x - 1] = 'P';
		break;
	}
	map[posP.y][posP.x] = ' ';
	return (map);
}
