/*
** EPITECH PROJECT, 2020
** MUL_game
** File description:
** display_text.c
*/

#include "my.h"
#include "gui.h"

void display_texts(sfRenderWindow *window, sfText **texts)
{
    if (texts && window)
        for (size_t a = 0; texts[a]; a++) {
            sfRenderWindow_drawText(window, texts[a], NULL);
        }
}

void display_one_text(sfRenderWindow *window, sfText *text)
{
    if (text && window)
        sfRenderWindow_drawText(window, text, NULL);
}