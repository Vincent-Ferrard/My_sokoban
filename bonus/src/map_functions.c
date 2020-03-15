/*
** EPITECH PROJECT, 2017
** map_functions.c
** File description:
** all map functions
*/

#include "main.h"

int find_max_line(char *path_map)
{
	int fd;
	int max_line = 0;
	char c;

	fd = open(path_map, O_RDONLY);
	while (read(fd, &c, 1)) {
		if (c == '\n')
			max_line++;
	}
	close(fd);
	return (max_line);
}

char **init_map(char *path_map, int max_line)
{
	FILE *file;
	char **map = malloc(sizeof(char *) * max_line);
	int i = 0;
	size_t len = 0;

	file = fopen(path_map, "r");
	if (!file)
		exit(84);
	while (getline(&map[i], &len, file) != -1)
		i++;
	fclose(file);
	return (map);
}

void display_map(char **map, int max_line)
{
	int j = 0;
	int i = 0;

	for (j = 0; j < max_line; j++) {
		for (i = 0; map[j][i]; i++)
			printw("%c", map[j][i]);
	}
}
