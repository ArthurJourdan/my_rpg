/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** stopping_events.c
*/

#include "global.h"
#include "shorting_defines.h"
#include "button.h"

bool pause_events(global_t *global, N_U sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        if (ACT == GAME) {
            change_scene(GSC, PAUSE);
        } else if (ACT == HOME) {
            sfRenderWindow_close(GW);
            return true;
        }
    }
    return false;
}

bool stopping_events(global_t *global, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(GW);
        return true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDelete)) {
        sfRenderWindow_close(GW);
        return true;
    }
    if (GGP.hp <= 0) {
        go_restart(global);
        return true;
    }
    return false;
}
