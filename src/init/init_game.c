/*
** EPITECH PROJECT, 2020
** init_game.c
** File description:
** initialize game struct
*/

#include "my_rpg.h"
#include "sfml_tools.h"

static const sfVector2f DIR = {-0.2, 1.0};

static void init_game_rain(global_t *global)
{
    int rd = 0;

    GGPXS(0) = 25.0;
    GGPR(0) = 3000;
    GGPS(0) = malloc(sizeof(sfVector2f) * GGPR(0));
    GGPP(0) = malloc(sizeof(sfVector2f) * GGPR(0));
    GGPE(0) = malloc(sizeof(sfVector2f) * GGPR(0));
    GGPX(0) = malloc(sizeof(float) * (GGPR(0) + 1));
    for (int i = 0; i != GGPR(0); i++) {
        rd = rand() % GGH + GGH / 2;
        GGPS(0)[i] = sfV2F{3000 / GGPR(0) * (i + 1), rand() % GGH - GGH};
        GGPP(0)[i] = sfV2F{GGPS(0)[i].x, GGPS(0)[i].y};
        GGPE(0)[i] = sfV2F{GGPS(0)[i].x + (rd * DIR.x),
        GGPS(0)[i].y + (rd * DIR.y)};
        GGPX(0)[i] = rand() % 3 + 1;
    }
}

static void init_game_snow(global_t *global)
{
    int rd = 0;

    GGPXS(1) = 5.0;
    GGPR(1) = 2000;
    GGPS(1) = malloc(sizeof(sfVector2f) * GGPR(1));
    GGPP(1) = malloc(sizeof(sfVector2f) * GGPR(1));
    GGPE(1) = malloc(sizeof(sfVector2f) * GGPR(1));
    GGPX(1) = malloc(sizeof(float) * GGPR(1));
    for (int i = 0; i != GGPR(1); i++) {
        rd = rand() % GGH + GGH / 2;
        GGPS(1)[i] = sfV2F{3000 / GGPR(1) * (i + 1), rand() % GGH - GGH};
        GGPP(1)[i] = sfV2F{GGPS(1)[i].x, GGPS(1)[i].y};
        GGPE(1)[i] = sfV2F{GGPS(1)[i].x + (rd * DIR.x),
        GGPS(1)[i].y + (rd * DIR.y)};
        GGPX(1)[i] = rand() % 3 + 1;
    }
}

static void init_game_vars(global_t *global)
{
    if (GGM > 20 || GGM <= 0)
        GGM = 5;
    GGW = sfRenderWindow_getSize(GW).x;
    GGH = sfRenderWindow_getSize(GW).y;
    GGF = framebuffer_create(GGW, GGH);
    GGTF = sfTexture_create(GGW, GGH);
    GGSF = sfSprite_create();
    sfSprite_setTexture(GGSF, GGTF, sfFalse);
    GG.pixel = malloc(sizeof(pixel_t) * 2);
    init_game_rain(global);
    init_game_snow(global);
}

void init_game(global_t *global)
{
    init_game_vars(global);
    GG.obj = malloc(sizeof(obj_t));
    GG.obj->s_obj = malloc(sizeof(s_obj_t) * 2);
    GG.obj->obj_index = 0;
    init_spell_obj(global);
    init_player(global);
    init_spell_obj_g(global);
    init_layers(global);
    HEALTHBARSPR = sprite_create_from_file(HEALTHBARPATH);
    PHEALTHBARSPR = sprite_create_from_file(PHEALTHBARPATH);
    enemy_tab_init(global);
}
