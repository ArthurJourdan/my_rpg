/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** event_management.c
*/

#include "global.h"

#include "events.h"

void event_management(global_t *global)
{
    sfEvent event;

    if (!(sfRenderWindow_pollEvent(GW, &event)))
        return;
    if (stopping_events(global, event)) {
        return;
    }

}