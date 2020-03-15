/*
** EPITECH PROJECT, 2017
** level.c
** File description:
** level
*/

#include "main.h"

int event_level(WINDOW *win, int pos)
{
	switch (getch()) {
	case KEY_DOWN:
		pos = up_level_condition(pos);
		break;
	case KEY_UP:
		if (pos == 4)
			pos = 3;
		else if (pos == 3)
			pos = 2;
		else
			pos = 1;
		break;
	case 10:
		if (pos == 4)
			init_menu(win);
		else
			level_status(win, pos);
		break;
	}
	return (pos);
}

int up_level_condition(int pos)
{
	if (pos == 1)
		pos = 2;
	else if (pos == 2)
		pos = 3;
	else
		pos = 4;
	return (pos);
}

void display_level(WINDOW *win, int pos)
{
	printw("#=================#\n");
	printw("|     Level 1     |\n");
	printw("|                 |\n");
	printw("|     Level 2     |\n");
	printw("|                 |\n");
	printw("|     Level 3     |\n");
	printw("|                 |\n");
	printw("|     Return      |\n");
	printw("#=================#\n");
	if (pos == 1)
		mvwprintw(win, 1, 2, "->");
	if (pos == 2)
		mvwprintw(win, 3, 2, "->");
	if (pos == 3)
		mvwprintw(win, 5, 2, "->");
	if (pos == 4)
		mvwprintw(win, 7, 2, "->");
}

void init_level(WINDOW *win)
{
	int pos = 1;

        while (1) {
		clear();
		display_level(win, pos);
		pos = event_level(win, pos);
        }
}

void level_status(WINDOW *win, int lv)
{
	FILE *file;
	size_t len = 0;
	char *str = malloc(sizeof(char) * 7);

	clear();
	file = fopen("map/score", "r");
	getline(&str, &len, file);
	fclose(file);
	if (str[0] - '0' >= lv - 1) {
		level_go(win, file, str, lv);
	} else {
		clear();
		mvprintw(getmaxy(win) / 2, getmaxx(win) / 2 - 16,
			 "Complete the previous level first");
		getch();
	}
}
