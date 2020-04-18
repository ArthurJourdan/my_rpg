/*
** EPITECH PROJECT, 2020
** init_player.c
** File description:
** initialize player struct
*/

#include "my_rpg.h"

void init_player(player_t *player)
{
    printf("player\n");
    player->hp = 100;
    init_controls(&player->controls);
}
