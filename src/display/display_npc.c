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
    if (!NPCS_ONE || !NPCS)
        return;
    sfSprite_setPosition(NPCS, NPC_POS);
    display_one_sprite(GW, NPCS);
}