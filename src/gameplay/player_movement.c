/*
** EPITECH PROJECT, 2020
** player_movement.c
** File description:
** player movements manager
*/

#include <SFML/Window/Export.h>
#include <SFML/Window/Keyboard.h>
#include <math.h>
#include "my_rpg.h"

void line_player_deplacement(player_t *player)
{
    if (player->controls.on_up && !player->controls.on_left &&
        !player->controls.on_down && !player->controls.on_right) {
        player->pos.y -= player->speed;
    }
    if (!player->controls.on_up && player->controls.on_left &&
        !player->controls.on_down && !player->controls.on_right) {
        player->pos.x -= player->speed;
    }
    if (!player->controls.on_up && !player->controls.on_left &&
        player->controls.on_down && !player->controls.on_right) {
        player->pos.y += player->speed;
    }
    if (!player->controls.on_up && !player->controls.on_left &&
        !player->controls.on_down && player->controls.on_right) {
        player->pos.x += player->speed;
    }
}

void diag_player_deplacement(player_t *player)
{
    if (player->controls.on_up && player->controls.on_left) {
        player->pos.y -= sin(M_PI / 4) * player->speed;
        player->pos.x -= cos(M_PI / 4) * player->speed;
    }
    if (player->controls.on_left && player->controls.on_down) {
        player->pos.y += sin(M_PI / 4) * player->speed;
        player->pos.x -= cos(M_PI / 4) * player->speed;
    }
    if (player->controls.on_down && player->controls.on_right) {
        player->pos.y += sin(M_PI / 4) * player->speed;
        player->pos.x += cos(M_PI / 4) * player->speed;
    }
    if (player->controls.on_right && player->controls.on_up) {
        player->pos.y -= sin(M_PI / 4) * player->speed;
        player->pos.x += cos(M_PI / 4) * player->speed;
    }
}

void player_key_pressed(player_t *player)
{
    if (sfKeyboard_isKeyPressed(player->controls.up)) {
        player->controls.on_up = true;
        put_sprite(player, "src/init/player_sprite/up2.png");
    } else
        player->controls.on_up = false;
    if (sfKeyboard_isKeyPressed(player->controls.left)) {
        player->controls.on_left = true;
        put_sprite(player, "src/init/player_sprite/left2.png");
    } else
        player->controls.on_left = false;
    if (sfKeyboard_isKeyPressed(player->controls.down)) {
        player->controls.on_down = true;
        put_sprite(player, "src/init/player_sprite/down2.png");
    } else
        player->controls.on_down = false;
    if (sfKeyboard_isKeyPressed(player->controls.right)) {
        player->controls.on_right = true;
        put_sprite(player, "src/init/player_sprite/right2.png");
    } else
        player->controls.on_right = false;
}

void check_next_pos(player_t *player, sfVector2f *next_pos)
{
    if (player->controls.on_up)
        next_pos->y = (player->pos.y - player->speed) - player->hitbox;
    if (player->controls.on_down)
        next_pos->y = (player->pos.y + player->speed) + player->hitbox;
    if (player->controls.on_left)
        next_pos->x = (player->pos.x - player->speed) - player->hitbox;
    if (player->controls.on_right)
        next_pos->x = (player->pos.x + player->speed) + player->hitbox;
    if (next_pos->x < 0)
        next_pos->x = 0;
    if (next_pos->y < 0)
        next_pos->y = 0;
    if (next_pos->x > 1650)
        next_pos->x = 1650;
    if (next_pos->y > 990)
        next_pos->y = 990;
}

void player_movements(player_t *player, layers_t *layers)
{
    sfVector2f next_pos = {player->pos.x, player->pos.y};
    sfColor color;

    player_key_pressed(player);
    check_next_pos(player, &next_pos);
    color = sfImage_getPixel((*layers).collision, next_pos.x + 1, next_pos.y + 1);
    if (color.r == 255 && color.g == 255 && color.b == 255 &&
        next_pos.x > 0 && next_pos.x < 1920 &&
        next_pos.y > 0 && next_pos.y < 1080) {
        line_player_deplacement(player);
        diag_player_deplacement(player);
    } else if (color.r == 255 && color.g == 0 && color.b == 0) {
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
