/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** go_back_to_game.c
*/

#include "global.h"
#include "gui.h"

global_t *go_back_to_game(global_t *global)
{
    change_scene(GS, GAME);
    return global;
}