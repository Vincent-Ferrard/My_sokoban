/*
** EPITECH PROJECT, 2017
** menu.c
** File description:
** menu
*/

#include "main.h"

int event_menu(WINDOW *win, int pos)
{
	switch (getch()) {
	case KEY_DOWN:
		if (pos == 1)
			pos = 2;
		else
			pos = 3;
		break;
	case KEY_UP:
		if (pos == 3)
			pos = 2;
		else
			pos = 1;
		break;
	case 10:
		choice_menu(win, pos);
		break;
	}
	return (pos);
}

void choice_menu(WINDOW *win, int pos)
{
	int fd;
	char c;

	if (pos == 1)
		init_level(win);
	else if (pos == 2) {
		fd = open("map/score", O_RDONLY);
		read(fd, &c, 1);
		close(fd);
		clear();
		mvprintw(getmaxy(win) / 2, getmaxx(win) / 2 - 11,
			 "Max level complete : %c", c);
		getch();
	} else {
		refresh();
		endwin();
		exit(0);
	}
}

void display_menu(WINDOW *win, int pos)
{
	printw("#==============#\n");
	printw("|     Play     |\n");
	printw("|              |\n");
	printw("|     Score    |\n");
	printw("|              |\n");
	printw("|     Quit     |\n");
	printw("#==============#\n");
	if (pos == 1)
		mvwprintw(win, 1, 2, "->");
	else if (pos == 2)
		mvwprintw(win, 3, 2, "->");
	else
		mvwprintw(win, 5, 2, "->");
}

void init_menu(WINDOW *win)
{
	int pos = 1;

	while (1) {
		clear();
		display_menu(win, pos);
		pos = event_menu(win, pos);
	}
}
