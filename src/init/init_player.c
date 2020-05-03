/*
** EPITECH PROJECT, 2020
** init_player.c
** File description:
** initialize player struct
*/

#include "my_rpg.h"

static const char *FILEPATH = "assets_rpg/images/player_sprite/down2.png";
static const char *PLAYER_SHEET = "assets_rpg/images/player_sprite/actor3.png";
static const char *DASH_SHEET = "assets_rpg/images/player_sprite/mist.png";
static const sfVector2f COLLIDER = {50, 75};
static const float HITBOX = 20;

static void init_player_sprites(global_t *global)
{
    animd_t anim;

    anim.spritesheet = my_strcpy((char *)PLAYER_SHEET);
    anim.anim_count = 4;
    anim.anim_frames = (int[4]){3, 3, 3, 3};
    anim.unit_size = (sfVector2f){96, 96};
    GGP.ss = spritesheet_load(&anim);
    free(anim.spritesheet);
}

static void init_dash_sprites(global_t *global)
{
    animd_t anim;

    anim.spritesheet = my_strcpy((char *)DASH_SHEET);
    anim.anim_count = 1;
    anim.anim_frames = (int[1]){6};
    anim.unit_size = (sfVector2f){192, 192};
    GGPD.dash = dash_spritesheet_load(&anim);
    GGPD.frame = 0;
    GGPD.pos = (sfVector2f)GGP.pos;
    GGPD.clock = sfClock_create();
    GGPD.angle = 0;
    free(anim.spritesheet);
}

void put_sprite(global_t *global, char *filepath)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    GGP.sprite = sfSprite_create();
    sfSprite_setTexture(GGP.sprite, texture, false);
    sfSprite_setOrigin(GGP.sprite, GGP.col_center);
}

static void init_player_vars(global_t *global)
{
    GGP.max_hp = 100;
    GGP.hp = 100;
    GGP.max_speed = 4;
    GGP.speed = 4;
    GGP.frame = 0;
    GGP.idle = true;
    GGP.pos = (sfVector2f){200, 500};
    GGP.hitbox = HITBOX;
    GGP.col_center = COLLIDER;
}

void init_player(global_t *global)
{
    init_player_vars(global);
    GGP.collider = malloc(sizeof(sfIntRect));
    GGP.collider->left = COLLIDER.x - 20;
    GGP.collider->top = COLLIDER.y - 20;
    GGP.collider->height = 20;
    GGP.collider->width = 20;
    put_sprite(global, (char *)FILEPATH);
    init_controls(global);
    init_player_sprites(global);
    init_dash_sprites(global);
    init_player_inventory(&GGP);
    GGP.clock = sfClock_create();
    GGPT = sfClock_getElapsedTime(GGP.clock);
    GGPL = 1;
}
