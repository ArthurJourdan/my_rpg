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
}

void display_layer2(sfRenderWindow *window, global_t *global)
{
    sfRenderWindow_drawSprite(window, GGLMM[GGLP.y][GGLP.x].lay2, NULL);
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

    sfSprite_setPosition(GGP.sprite, GGP.pos);
    display_dash(window, global);
    sfRenderWindow_drawSprite(window, GGP.sprite, NULL);
    if (timer > 100000) {
        GGP.frame = ((GGP.frame == 2) ? 0 : GGP.frame + 1);
        GGP.time = sfClock_getElapsedTime(GGP.clock);
    }
}
