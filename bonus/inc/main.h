/*
** EPITECH PROJECT, 2017
** main.h
** File description:
** main sokoban header
*/

#ifndef MAIN_H_
#define MAIN_H_

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "struct.h"
#include "all_check.h"
#include "all_map_functions.h"
#include "error.h"
#include "event.h"
#include "objective.h"
#include "player_func.h"

void game_map(WINDOW *, char *, int);
void call_all_func(WINDOW *, char **, pos_t, int);
int main(int, char **);

int event_level(WINDOW *, int);
int up_level_condition(int);
void display_level(WINDOW *, int);
void init_level(WINDOW *);
void level_status(WINDOW *, int);
void level_go(WINDOW *, FILE *, char *, int);

int event_menu(WINDOW *, int);
void display_menu(WINDOW *, int);
void init_menu(WINDOW *);
void choice_menu(WINDOW *, int);

#endif
