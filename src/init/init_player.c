/*
** EPITECH PROJECT, 2020
** init_player.c
** File description:
** initialize player struct
*/

#include "my_rpg.h"

static const char FILEPATH[32] = "src/init/player_sprite/down2.png";
static const sfVector2f COLLIDER = {50, 75};
static const float HITBOX = 20;

void put_sprite(player_t *player, char *filepath)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    player->sprite = sfSprite_create();
    sfSprite_setTexture(player->sprite, texture, false);
    sfSprite_setOrigin(player->sprite, player->collider);
}

void init_player(player_t *player)
{
    player->max_speed = 4;
    player->speed = 4;
    player->idle = true;
    player->pos = (sfVector2f){200, 500};
    player->hitbox = HITBOX;
    player->collider = COLLIDER;
    put_sprite(player, (char *)FILEPATH);
    init_controls(&player->controls);
}
