/*
** EPITECH PROJECT, 2020
** MUL_game
** File description:
** display_buttons.c
*/

#include "my.h"
#include "gui.h"

void display_buttons(sfRenderWindow *window, button_t **buttons)
{
    for (size_t a = 0; buttons && buttons[a]; a++) {
        if (buttons[a]->rect) {
            sfRenderWindow_drawRectangleShape(window, buttons[a]->rect, NULL);
        }
        if (buttons[a]->text) {
            sfRenderWindow_drawText(window, buttons[a]->text, NULL);
        }
    }
}
