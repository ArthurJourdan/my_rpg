/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** stopping_events.c
*/

#include "global.h"

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