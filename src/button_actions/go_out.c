/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** go_out.c
*/

#include "global.h"
#include "gui.h"

global_t *go_out(global_t *global)
{
    sfRenderWindow_close(GW);
    return global;
}