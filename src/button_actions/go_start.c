/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** go_start.c
*/

#include "global.h"
#include "gui.h"

global_t *go_start(global_t *global)
{
    // reset_all_game(global);
    change_scene(GS, GAME);
    return global;
}