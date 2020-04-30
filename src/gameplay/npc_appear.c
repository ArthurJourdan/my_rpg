/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** npc_appear.c
*/

#include "my.h"

#include "rpg_structs.h"
#include "global.h"

void npc_appear(global_t *global)
{
    if (global->game.layers.pos.x != 0 && global->game.layers.pos.y != 0)
        return;

}