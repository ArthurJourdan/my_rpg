/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** display_npc.c
*/

#include "global.h"
#include "sfml_tools.h"

void display_npc(global_t *global, size_t npc_idx)
{
    if (!NPCS_ONE)
        return;
    if (!NPCS)
        return;
    sfSprite_setPosition(NPCS, NPC_POS);
    display_one_sprite(GW, global->game.npc_list[npc_idx]->sprite[0][0]);
}
