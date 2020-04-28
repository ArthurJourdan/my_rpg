/*
** EPITECH PROJECT, 2020
** init_game.c
** File description:
** initialize game struct
*/

#include "my_rpg.h"

void init_game(global_t *global)
{
    init_player(global);
    init_layers(global);
}
