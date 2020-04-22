/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** event_management.c
*/

#include "global.h"

#include "events.h"

sfVector2f get_mouse_coo(sfRenderWindow *win)
{
    sfVector2f mouse = {0, 0};

    mouse.x = (float)sfMouse_getPositionRenderWindow(win).x;
    mouse.y = (float)sfMouse_getPositionRenderWindow(win).y;
    return mouse;
}

void event_management(global_t *global)
{
    if (stopping_events(global, GG.event))
        return;
    if (button_management(global, GG.event))
        return;

}
