/*
** EPITECH PROJECT, 2020
** MUL_game
** File description:
** display_sprites.c
*/

#include "my.h"
#include "gui.h"

void display_one_sprite(sfRenderWindow *window, sfSprite *sprite)
{
    if (sprite && window) {
        sfRenderWindow_drawSprite(window, sprite, NULL);
    }
}

void display_images(sfRenderWindow *window, sfSprite **images)
{
    if (images && window)
        for (size_t a = 0; images[a]; a++) {
            sfRenderWindow_drawSprite(window, images[a], NULL);
        }
}
