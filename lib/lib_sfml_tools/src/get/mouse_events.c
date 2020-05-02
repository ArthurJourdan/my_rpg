/*
** EPITECH PROJECT, 2020
** MUL_
** File description:
** mouse_events.c
*/

#include "sfml_tools.h"
#include <stdbool.h>

sfVector2f get_mouse_coo(sfRenderWindow *win)
{
    sfVector2f mouse = {0, 0};

    if (!win)
        return mouse;
    mouse.x = (float)sfMouse_getPositionRenderWindow(win).x;
    mouse.y = (float)sfMouse_getPositionRenderWindow(win).y;
    return mouse;
}

bool left_mouse_pressed(sfEvent event)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        return true;
    }
    return false;
}

bool right_mouse_pressed(sfEvent event)
{
    if (sfMouse_isButtonPressed(sfMouseRight)) {
        return true;
    }
    return false;
}

bool left_mouse_released(sfEvent event)
{
    if (event.type == sfEvtMouseButtonReleased) {
        if (event.mouseButton.button == sfMouseLeft)
            return true;
    }
    return false;
}

bool right_mouse_released(sfEvent event)
{
    if (event.type == sfEvtMouseButtonReleased) {
        if (event.mouseButton.button == sfMouseRight)
            return true;
    }
    return false;
}
