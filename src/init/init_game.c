/*
** EPITECH PROJECT, 2020
** init_game.c
** File description:
** initialize game struct
*/

#include "my_rpg.h"

void init_game(game_t *game)
{
    init_player(&game->player);
    init_layers(&game->layers);
}
