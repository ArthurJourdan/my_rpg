/*
** EPITECH PROJECT, 2020
** image_cmp
** File description:
** compare pixels of th sfImage
*/

#include "my_rpg.h"

void move_check(sfVector2f next, player_t *player, layers_t *layers)
{
    sfColor color = sfImage_getPixel((*layers).collision, next.x, next.y);

    if (!my_colorcmp(color, sfBlack) &&
        next.x > 0 && next.x < 1650 &&
        next.y > 0 && next.y < 990) {
        if (player->controls.on_dash) {
            line_player_deplacement(player);
            diag_player_deplacement(player);
        } else if (!my_colorcmp(color, sfBlue)) {
            line_player_deplacement(player);
            diag_player_deplacement(player);
        }
    }
}

void swap_map(sfVector2f next, player_t *player, layers_t *layers)
{
    sfColor color = sfImage_getPixel((*layers).collision, next.x, next.y);

    if (my_colorcmp(color, sfRed)) {
        layers->nb++;
        if (player->pos.x > 1350)
            player->pos.x = 100;
        else if (player->pos.x < 300)
            player->pos.x = 1550;
        if (player->pos.y > 600)
            player->pos.y = 100;
        else if (player->pos.y < 300)
            player->pos.y = 900;
        my_putmap(layers,
                  layers->maps[0][layers->nb % 7],
                  layers->maps[1][layers->nb % 7],
                  layers->maps[2][layers->nb % 7]);
    }
}

void player_dash(sfVector2f next, player_t *player, layers_t *layers)
{
    sfColor color = sfImage_getPixel((*layers).collision, next.x, next.y);
    float speed = player->speed * 4;

    if (sfKeyboard_isKeyPressed(player->controls.dash) && player->controls.dash_enable) {
        sfClock_restart(player->controls.dash_clock);
        sfClock_restart(player->controls.clock);
        player->controls.dash_enable = false;
        player->controls.on_dash = true;
        if (my_colorcmp(color, sfWhite))
            player->speed = speed;
    }
    if (sfClock_getElapsedTime(player->controls.clock).microseconds > 100000) {
        player->controls.on_dash = false;
        player->speed = player->max_speed;
    }
    if (sfClock_getElapsedTime(player->controls.dash_clock).microseconds > 1000000)
        player->controls.dash_enable = true;
}
