/*
** EPITECH PROJECT, 2017
** level_go.c
** File description:
** level end
*/

#include "main.h"

void level_go(WINDOW *win, FILE *file, char *str, int lv)
{
	size_t len = 0;
	int i = 0;

	file = fopen("map/level", "r");
	while (i < lv) {
		getline(&str, &len, file);
		i++;
	}
	fclose(file);
	while (str[i])
		i++;
	str[i - 1] = '\0';
	refresh();
	game_map(win, str, lv);
}
