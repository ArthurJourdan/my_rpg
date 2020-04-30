/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** npc_appear.c
*/

#include "my.h"

#include "rpg_structs.h"
#include "global.h"
#include "sfml_tools.h"
#include "shorting_defines.h"

static void action_npc(global_t *global, size_t npc_idx)
{
    if (left_mouse_pressed(global->event))
        GGNPC[npc_idx]->action(global);
}

void npc_appear(global_t *global)
{
    for (size_t a = 0; GGNPC[a]; a++) {
        if (GGLP.x == GGNPC[a]->map_pos.x && GGLP.y == GGNPC[a]->map_pos.y)
            action_npc(global, a);
    }
}