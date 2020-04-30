/*
** EPITECH PROJECT, 2020
** check_collision
** File description:
** checks if two objects are colliding
*/

#include "rpg_structs.h"

int player_is_colliding(game_t *game)
{
    for (int i = 0; i < 64; i++)
        if (sfIntRect_intersects(game->player.collider,
        game->obj->e_obj[i].collider, NULL))
            return i;
    return 0;
}
