/*
** EPITECH PROJECT, 2020
** MUL_game
** File description:
** display_sprites.c
*/

#include "my.h"
#include "gui.h"

// void display_linked_list(sfRenderWindow *window, game_object_t *game_o)
// {
    // game_object_t *temp = game_o;

    // while (temp && window) {
        // if (temp->sprite)
            // sfRenderWindow_drawSprite(window, temp->sprite, NULL);
        // temp = temp->next;
    // }
// }

void display_one_sprite(sfRenderWindow *window, sfSprite *sprite)
{
    if (sprite && window) {
        sfRenderWindow_drawSprite(window, sprite, NULL);
    }
}

// void display_sprites(sfRenderWindow *window, game_object_t **game_object)
// {
    // if (game_object && window)
        // for (size_t a = 0; game_object[a]; a++) {
            // if (game_object[a]->sprite)
                // display_linked_list(window, game_object[a]);
        // }
// }

void display_images(sfRenderWindow *window, sfSprite **images)
{
    if (images && window)
        for (size_t a = 0; images[a]; a++) {
            sfRenderWindow_drawSprite(window, images[a], NULL);
        }
}
