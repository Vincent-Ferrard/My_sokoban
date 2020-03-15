/*
** EPITECH PROJECT, 2017
** help.c
** File description:
** help my_sokoban
*/

#include "main.h"

void my_putchar(char c)
{
        write(1, &c, 1);
}

void my_putstr(char *str)
{
        for (int i = 0; str[i]; i++)
                my_putchar(str[i]);
}

void help(int ac, char **av)
{
	if (ac > 1 && av[1][0] == '-' && av[1][1] == 'h') {
		my_putstr("USAGE\n");
		my_putstr("               ./my_sokoban map");
		my_putstr("\n\nDESCRIPTION\n");
		my_putstr("               map    file ");
		my_putstr("representing the warehouse map, containing");
		my_putstr(" '#' for walls, 'P' for the player, 'X' for");
		my_putstr(" boxes and 'O' for storage locations.\n");
		exit(84);
	}
}
