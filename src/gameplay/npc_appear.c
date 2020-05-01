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
    sfVector2f pos_mouse = {0, 0};
    sfIntRect sprite_coo = {0, 0, 0, 0};

    if (!NPCS_ONE || !NPCS)
        return;
    pos_mouse = get_mouse_coo(GW);
    sprite_coo = sfSprite_getTextureRect(NPCS);
    if (left_mouse_pressed(global->event)) {
        if (sfIntRect_contains(&sprite_coo, pos_mouse.x, pos_mouse.y)) {
            GGNPC[npc_idx]->actioning = true;
        }
    }
}

void npc_appear(global_t *global)
{
    for (size_t npc_idx = 0; GGNPC[npc_idx]; npc_idx++) {
        if (GGLP.x == NPC_MAPX && GGLP.y == NPC_MAPY) {
            display_npc(global, npc_idx);
            action_npc(global, npc_idx);
        }
    }
    for (size_t npc_idx = 0; GGNPC[npc_idx]; npc_idx++) {
        if (GGNPC[npc_idx]->actioning && GGNPC[npc_idx]->action)
            GGNPC[npc_idx]->action(global, npc_idx);
    }
}