/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** stopping_events.c
*/

#include "global.h"
#include "shorting_defines.h"

bool pause_events(global_t *global, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
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
    if(event.type == sfEvtKeyPressed && event.key.code == sfKeyDelete) {
        sfRenderWindow_close(GW);
        return true;
    }
    return false;
}