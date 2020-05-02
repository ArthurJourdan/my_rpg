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
    if (stopping_events(global, GG.event))
        return;
    if (pause_events(global, GG.event))
        return;
    if (button_management(global, GG.event))
        return;
}
