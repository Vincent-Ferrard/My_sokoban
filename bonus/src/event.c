/*
** EPITECH PROJECT, 2017
** event.c
** File description:
** all event
*/

#include "main.h"

char **game_key_event(WINDOW *win, char **map, pos_t posP)
{
	int ch = getch();

	switch (ch) {
	case KEY_DOWN:
		map = move_player(map, posP, posP.y + 1, posP.x);
		map = boxes_conditions(map, posP, posP.y + 1, posP.x);
		break;
	case KEY_UP:
		map = move_player(map, posP, posP.y - 1, posP.x);
		map = boxes_conditions(map, posP, posP.y - 1, posP.x);
		break;
	case 27:
		init_level(win);
		break;
	default:
		map = game_key_event_end(map, posP, ch);
		break;
	}
	return (map);
}

char **game_key_event_end(char **map, pos_t posP, int ch)
{
	switch (ch) {
	case KEY_LEFT:
		map = move_player(map, posP, posP.y, posP.x - 1);
		map = boxes_conditions(map, posP, posP.y, posP.x - 1);
		break;
	case KEY_RIGHT:
		map = move_player(map, posP, posP.y, posP.x + 1);
		map = boxes_conditions(map, posP, posP.y, posP.x + 1);
		break;
	}
	return (map);
}
