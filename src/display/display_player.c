/*
** EPITECH PROJECT, 2020
** display_player.c
** File description:
** draw player
*/

#include "my_rpg.h"

void display_layer1(sfRenderWindow *window, global_t *global)
{
    sfRenderWindow_drawSprite(window, GGLMM[GGLP.y][GGLP.x].lay1, NULL);
    if (GGLP.x >= (GGM - 1) || !GGLMM[GGLP.y][GGLP.x + 1].is_open)
        sfRenderWindow_drawSprite(window, GGL.wall[2], NULL);
    if (GGLP.x <= 0 || !GGLMM[GGLP.y][GGLP.x - 1].is_open)
        sfRenderWindow_drawSprite(window, GGL.wall[0], NULL);
    if (GGLP.y >= (GGM - 1) || !GGLMM[GGLP.y + 1][GGLP.x].is_open)
        sfRenderWindow_drawSprite(window, GGL.wall[1], NULL);
    if (GGLP.y <= 0 || !GGLMM[GGLP.y - 1][GGLP.x].is_open)
        sfRenderWindow_drawSprite(window, GGL.wall[3], NULL);
}

void display_layer2(sfRenderWindow *window, global_t *global)
{
    sfRenderWindow_drawSprite(window, GGLMM[GGLP.y][GGLP.x].lay2, NULL);
    if (GGLMM[GGLP.y][GGLP.x].weather == 0)
        make_it_rain(global);
    if (GGLMM[GGLP.y][GGLP.x].weather == 1)
        make_it_snow(global);
}

static void display_dash(sfRenderWindow *window, global_t *global)
{
    sfSprite_setPosition(GGPD.dash[0][GGPD.frame], GGPD.pos);
    sfRenderWindow_drawSprite(window, GGPD.dash[0][GGPD.frame], NULL);
    if (sfClock_getElapsedTime(GGPD.clock).microseconds > 100000) {
        sfClock_restart(GGPD.clock);
        if (GGPD.frame < 5)
            GGPD.frame++;
    }
}

void display_player(sfRenderWindow *window, global_t *global)
{
    sfTime time = sfClock_getElapsedTime(GGP.clock);
    int timer = time.microseconds - GGPT.microseconds;
    sfVector2u size = sfTexture_getSize(sfSprite_getTexture(PHEALTHBARSPR));

    size.x = size.x * GGP.hp / GGP.max_hp;
    sfSprite_setTextureRect(PHEALTHBARSPR, rect(0, 0, size.x, size.y));
    sfSprite_setPosition(PHEALTHBARSPR, vec2f(GGP.pos.x, GGP.pos.y - 30));
    sfRenderWindow_drawSprite(GW, PHEALTHBARSPR, NULL);
    sfSprite_setPosition(GGP.sprite, GGP.pos);
    display_dash(window, global);
    sfRenderWindow_drawSprite(window, GGP.sprite, NULL);
    if (timer > 100000) {
        GGP.frame = ((GGP.frame == 2) ? 0 : GGP.frame + 1);
        GGP.time = sfClock_getElapsedTime(GGP.clock);
    }
}
