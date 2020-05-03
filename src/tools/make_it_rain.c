/*
** EPITECH PROJECT, 2020
** make_it_rain.c
** File description:
** pixel rain
*/

#include "my_rpg.h"
#include "sfml_tools.h"

static void rain_create(global_t *global, sfColor color)
{
    for (int i = 0; i != GGPR(0); i++) {
        put_square(global, GGPP(0)[i], sfV2F{GGPX(0)[i], GGPX(0)[i]}, color);
    }
}

static void snow_create(global_t *global, sfColor color)
{
    for (int i = 0; i != GGPR(1); i++) {
        put_square(global, GGPP(1)[i], sfV2F{GGPX(1)[i], GGPX(1)[i]}, color);
    }
}

void make_it_rain(global_t *global)
{
    rain_create(global, sfC{150, 150, 255, 255});
    sfTexture_updateFromPixels(GGTF, GGF->pixels, GGW, GGH, 0, 0);
    sfRenderWindow_drawSprite(GW, GGSF, NULL);
    rain_create(global, sfC{0, 0, 0, 0});
    for (int i = 0; i != GGPR(0); i++)
        my_goto(&GGPP(0)[i], GGPS(0)[i], GGPE(0)[i], GGPXS(0));
}

void make_it_snow(global_t *global)
{
    snow_create(global, sfWhite);
    sfTexture_updateFromPixels(GGTF, GGF->pixels, GGW, GGH, 0, 0);
    sfRenderWindow_drawSprite(GW, GGSF, NULL);
    snow_create(global, sfC{0, 0, 0, 0});
    for (int i = 0; i != GGPR(1); i++)
        my_goto(&GGPP(1)[i], GGPS(1)[i], GGPE(1)[i], GGPXS(1));
}
