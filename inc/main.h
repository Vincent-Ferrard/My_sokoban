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

void game_map(char *);
char **init_all(char *, int);
void call_all_func(char **, pos_t, int);
int main(int, char **);

#endif
