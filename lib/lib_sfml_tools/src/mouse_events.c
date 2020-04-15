/*
** EPITECH PROJECT, 2020
** MUL_
** File description:
** mouse_events.c
*/

#include "my.h"
#include "sfml_tools.h"

sfVector2f get_mouse_pressed_coo(sfRenderWindow *win)
{
    sfVector2f mouse = {0, 0};

    mouse.x = (float)sfMouse_getPositionRenderWindow(win).x;
    mouse.y = (float)sfMouse_getPositionRenderWindow(win).y;
    return mouse;
}

bool left_mouse_button_pressed(sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.mouseButton.button == sfMouseLeft)
            return true;
    }
    return false;
}

int where_mouse_button_pressed(sfRenderWindow *win, button_t **buttons)
{
    sfVector2f mouse = get_mouse_pressed_coo(win);
    sfVector2f pos_sqr = {0, 0};
    sfVector2f size_sqr = {0, 0};

    for (int a = 0; buttons[a]; a++) {
        pos_sqr = sfRectangleShape_getPosition(buttons[a]->button);
        size_sqr = sfRectangleShape_getSize(buttons[a]->button);
        if (mouse.x > pos_sqr.x && mouse.x < pos_sqr.x + size_sqr.x) {
            if (mouse.y > pos_sqr.y && mouse.y < pos_sqr.y + size_sqr.y) {
                return a;
            }
        }
    }
    return -1;
}

void check_mouse_on_button(sfRenderWindow *win, button_t **buttons)
{
    int a = where_mouse_button_pressed(win, buttons);

    if (a != -1) {
        sfRectangleShape_setOutlineColor(buttons[a]->button, sfBlack);
    }
    for (int b = 0; buttons[b]; b++) {
        if (b != a)
            sfRectangleShape_setOutlineColor(buttons[b]->button, sfWhite);
    }
}

