/*
** EPITECH PROJECT, 2017
** all_check.h
** File description:
** all_check header
*/

#ifndef ALL_CHECK_H_
#define ALL_CHECK_H_

#include "main.h"

void check_victory(WINDOW *, char **, pos_t *, int, int);
void put_score(int);
void check_defeat(WINDOW *, char **, int);
int cant_move_box(char **, int, int);
void close_win(WINDOW *, char *, int);

#endif
