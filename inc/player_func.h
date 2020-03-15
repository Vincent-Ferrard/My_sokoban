/*
** EPITECH PROJECT, 2017
** player_func.h
** File description:
** player functions header
*/

#ifndef PLAYER_FUNC_H_
#define PLAYER_FUNC_H_

#include "main.h"

pos_t find_pos_player(char **, int);
char **move_player(char **, pos_t, int, int);
char **boxes_conditions(char **, pos_t, int, int);
char **move_box(char **, pos_t, int);

#endif
