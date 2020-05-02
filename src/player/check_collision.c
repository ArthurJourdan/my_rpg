/*
** EPITECH PROJECT, 2020
** check_collision
** File description:
** checks if two objects are colliding
*/

#include "rpg_structs.h"
#include "stdio.h"

int player_colliding_spell(game_t *game, int index)
{
    if (sfIntRect_intersects(game->player.collider,
    game->obj->sp_obj_g[index].collider, NULL)) {
        return 1;
    }
    return 0;
}

int player_is_colliding(game_t *game)
{
    for (int i = 0; i < 64; i++)
        if (sfIntRect_intersects(game->player.collider,
        &game->e_obj[i]->collider, NULL))
            return i;
    return 0;
}
