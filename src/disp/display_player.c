/*
** EPITECH PROJECT, 2020
** display_player.c
** File description:
** draw player
*/

#include "my_rpg.h"

void display_player(sfRenderWindow *window, player_t player, layers_t layers)
{
    sfSprite_setPosition(player.sprite, player.pos);
    sfRenderWindow_drawSprite(window, layers.layer1, NULL);
    sfRenderWindow_drawSprite(window, player.sprite, NULL);
    sfRenderWindow_drawSprite(window, layers.layer2, NULL);
}
