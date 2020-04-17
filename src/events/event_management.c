/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** event_management.c
*/

#include "global.h"

#include "events.h"
#include "sfml_tools.h"

void event_management(global_t *global)
{
    sfRenderWindow_pollEvent(GW, &global->event);
    if (stopping_events(global, global->event))
        return;
    if (button_management(global, global->event))
        return;
}