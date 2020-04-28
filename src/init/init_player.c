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

void init_player_sprites(global_t *global)
{
    animd_t anim;

    anim.spritesheet = my_strcpy("src/init/player_sprite/actor3_ss.png");
    anim.anim_count = 4;
    anim.anim_frames = (int[4]){3, 3, 3, 3};
    anim.unit_size = (sfVector2i){96, 96};
    GGP.ss = spritesheet_load(&anim);
}

void init_dash_sprites(global_t *global)
{
    animd_t anim;

    anim.spritesheet = my_strcpy("src/init/player_sprite/mist.png");
    anim.anim_count = 1;
    anim.anim_frames = (int[1]){6};
    anim.unit_size = (sfVector2i){192, 192};
    GGPD.dash = dash_spritesheet_load(&anim);
    GGPD.frame = 0;
    GGPD.pos = (sfVector2f)GGP.pos;
    GGPD.clock = sfClock_create();
    GGPD.angle = 0;
}

void put_sprite(global_t *global, char *filepath)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    GGP.sprite = sfSprite_create();
    sfSprite_setTexture(GGP.sprite, texture, false);
    sfSprite_setOrigin(GGP.sprite, GGP.collider);
}

void init_player(global_t *global)
{
    GGP.max_speed = 4;
    GGP.speed = 4;
    GGP.frame = 0;
    GGP.idle = true;
    GGP.pos = (sfVector2f){200, 500};
    GGP.hitbox = HITBOX;
    GGP.collider = COLLIDER;
    put_sprite(global, (char *)FILEPATH);
    init_controls(global);
    init_player_sprites(global);
    init_dash_sprites(global);
    GGP.clock = sfClock_create();
    GGPT = sfClock_getElapsedTime(GGP.clock);
}
