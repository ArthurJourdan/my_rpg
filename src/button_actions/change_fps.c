/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** change_fps.c
*/

#include "global.h"

void increase_fps(global_t *global)
{
    global->fps++;
}

void decrease_fps(global_t *global)
{
    if (global->fps > 1)
        global->fps--;
}
