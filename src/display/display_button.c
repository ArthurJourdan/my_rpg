/*
** EPITECH PROJECT, 2020
** MUL_game
** File description:
** display_buttons.c
*/

#include "my.h"
#include "shorting_defines.h"
#include "gui.h"
#include "global.h"
#include "text.h"

void display_buttons(global_t *global)
{
    if (!global || !SC_A || !SC_B)
        return;
    for (size_t a = 0; SC_B[a]; a++) {
        if (SC_B[a]->rect) {
            sfRenderWindow_drawRectangleShape(GW, SC_B[a]->rect, NULL);
        }
    }
}
