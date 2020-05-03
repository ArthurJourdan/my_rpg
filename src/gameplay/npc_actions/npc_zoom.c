/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** npc_zoom.c
*/

#include "global.h"

static bool reset_my_view(global_t *global, size_t npc_idx, sfView *npc_view)
{
    sfTime passed = sfClock_getElapsedTime(GGNPC[npc_idx]->clock);

    if (sfTime_asSeconds(passed) >= GGNPC[npc_idx]->time_action) {
        sfRenderWindow_setView(GW, sfRenderWindow_getDefaultView(GW));
        sfView_destroy(npc_view);
        return true;
    }
    return false;
}

void npc_zoom(global_t *global, size_t npc_idx)
{
    static sfView *npc_view = NULL;

    if (!npc_view) {
        npc_view = sfView_copy(sfRenderWindow_getDefaultView(GW));
        sfView_setCenter(npc_view, NPC_POS);
    }
    sfView_zoom(npc_view, 0.99);
    sfRenderWindow_setView(GW, npc_view);
    if (reset_my_view(global, npc_idx, npc_view))
        npc_view = NULL;
}