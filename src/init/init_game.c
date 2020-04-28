/*
** EPITECH PROJECT, 2020
** init_game.c
** File description:
** initialize game struct
*/

#include "my_rpg.h"

void init_game(global_t *global)
{
    GGW = sfRenderWindow_getSize(GW).x;
    GGH = sfRenderWindow_getSize(GW).y;
    init_player(global);
    init_layers(global);
}
