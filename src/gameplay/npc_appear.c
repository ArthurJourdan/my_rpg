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
    sfFloatRect sprite_coo = {0, 0, 0, 0};

    if (!NPCS_ONE || !NPCS)
        return;
    pos_mouse = get_mouse_coo(GW);
    sprite_coo = sfSprite_getGlobalBounds(NPCS);
    if (left_mouse_pressed(global->event)) {
        if (sfFloatRect_contains(&sprite_coo, pos_mouse.x, pos_mouse.y)) {
            GGNPC[npc_idx]->actioning = true;
            sfClock_restart(GGNPC[npc_idx]->clock);
        }
    }
}

static void npc_disappear(global_t *global)
{
    sfTime passed;

    for (size_t npc_idx = 0; GGNPC[npc_idx]; npc_idx++) {
        passed = sfClock_getElapsedTime(GGNPC[npc_idx]->clock);
        if (sfTime_asSeconds(passed) > GGNPC[npc_idx]->time_action)
            GGNPC[npc_idx]->actioning = false;
    }

}

void npc_appear(global_t *global)
{
    if (!GGNPC)
        return;
    for (size_t npc_idx = 0; GGNPC[npc_idx]; npc_idx++) {
        if (GGLP.x == NPC_MAPX && GGLP.y == NPC_MAPY) {
            display_npc(global, npc_idx);
            action_npc(global, npc_idx);
        }
    }
    for (size_t npc_idx = 0; GGNPC[npc_idx]; npc_idx++) {
        if (GGNPC[npc_idx]->actioning && GGNPC[npc_idx]->action) {
            GGNPC[npc_idx]->action(global, npc_idx);
        }
    }
    npc_disappear(global);
}