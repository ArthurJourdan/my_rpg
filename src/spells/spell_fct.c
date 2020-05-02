/*
** EPITECH PROJECT, 2020
** spells_fct
** File description:
** spell functions
*/

#include "my_rpg.h"

void targeted_spell(game_t *game, int index)
{
    game->obj->s_obj[index].obj_status = true;
    game->obj->s_obj[index].starting_pos.x = game->player.pos.x;
    game->obj->s_obj[index].starting_pos.y = game->player.pos.y;
    game->obj->s_obj[index].pos.x = game->player.pos.x;
    game->obj->s_obj[index].pos.y = game->player.pos.y;
}
