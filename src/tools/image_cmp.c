/*
** EPITECH PROJECT, 2020
** image_cmp
** File description:
** compare pixels of th sfImage
*/

#include "my_rpg.h"

void move_check(sfVector2f next, global_t *global)
{
    sfColor color = sfImage_getPixel(GGL.collision, next.x, next.y);

    if (!my_colorcmp(color, sfBlack) &&
        next.x > 0 && next.x < 1650 &&
        next.y > 0 && next.y < 990) {
        if (GGPC.on_dash) {
            line_player_deplacement(global);
            diag_player_deplacement(global);
        } else if (!my_colorcmp(color, sfBlue)) {
            line_player_deplacement(global);
            diag_player_deplacement(global);
        }
    }
}

void swap_map(sfVector2f next, global_t *global)
{
    sfColor color = sfImage_getPixel(GGL.collision, next.x, next.y);

    if (!my_colorcmp(color, sfRed))
        return;
//        GGL.nb++;
    if (GGP.pos.x > 1350 && GGLMM[GGLP.y][GGLP.x + 1].is_open) {
        GGP.pos.x = 100;
        GGLP.x++;
    } else if (GGP.pos.x < 300 && GGLMM[GGLP.y][GGLP.x - 1].is_open) {
        GGP.pos.x = 1550;
        GGLP.x--;
    }
    if (GGP.pos.y > 600 && GGLMM[GGLP.y + 1][GGLP.x].is_open) {
        GGP.pos.y = 100;
        GGLP.y++;
    } else if (GGP.pos.y < 300 && GGLMM[GGLP.y - 1][GGLP.x].is_open) {
        GGP.pos.y = 900;
        GGLP.y--;
    }
//        my_putmap(global,
//                  GGL.maps[0][GGL.nb % 7],
//                  GGL.maps[1][GGL.nb % 7],
//                  GGL.maps[2][GGL.nb % 7]);
}

static void set_rotation_dash(global_t *global)
{
    for (int i = 0; i != 5; i++)
        sfSprite_setRotation(GGPD.dash[0][GGPD.frame], 90);
}

void player_dash(sfVector2f next, global_t *global, sfColor dash_color)
{
    sfColor color = sfImage_getPixel(GGL.collision, next.x, next.y);
    float speed = GGP.speed * 4;

    if (sfKeyboard_isKeyPressed(GGPC.dash) && GGPC.dash_enable && my_colorcmp(dash_color, sfWhite)) {
        sfClock_restart(GGPC.dash_clock);
        sfClock_restart(GGPC.clock);
        GGPD.pos = (sfVector2f)GGP.pos;
        GGPD.frame = 0;
        set_rotation_dash(global);
        GGPC.dash_enable = false;
        GGPC.on_dash = true;
        if (my_colorcmp(color, sfWhite) || my_colorcmp(color, sfBlue))
            GGP.speed = speed;
    }
    if (sfClock_getElapsedTime(GGPC.clock).microseconds > 100000) {
        GGPC.on_dash = false;
        GGP.speed = GGP.max_speed;
    }
    if (sfClock_getElapsedTime(GGPC.dash_clock).microseconds > 1000000)
        GGPC.dash_enable = true;
}
