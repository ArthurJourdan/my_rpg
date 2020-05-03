/*
** EPITECH PROJECT, 2020
** image_cmp
** File description:
** compare pixels of th sfImage
*/

#include "my_rpg.h"

void move_check(sfVector2f next, global_t *global)
{
    sfColor color = get_pixel_color(next, global);

    if (!my_colorcmp(color, sfBlack) &&
        next.x > 0 && next.x < GGW &&
        next.y > 0 && next.y < GGH) {
        if (GGPC.on_dash) {
            line_player_deplacement(global);
            diag_player_deplacement(global);
        } else if (!my_colorcmp(color, sfBlue)) {
            line_player_deplacement(global);
            diag_player_deplacement(global);
        }
    }
}

void dash_cooldown(global_t *global)
{
    if (sfClock_getElapsedTime(GGPC.clock).microseconds > 100000) {
        GGPC.on_dash = false;
        GGP.speed = GGP.max_speed;
    }
    if (sfClock_getElapsedTime(GGPC.dash_clock).microseconds > 1000000)
        GGPC.dash_enable = true;
}

void player_dash(sfVector2f next, global_t *global, sfColor dash_color)
{
    sfColor color = get_pixel_color(next, global);
    float speed = GGP.speed * 4;

    if (sfKeyboard_isKeyPressed(GGPC.dash) && GGPC.dash_enable &&
        my_colorcmp(dash_color, sfWhite)) {
        sfClock_restart(GGPC.dash_clock);
        sfClock_restart(GGPC.clock);
        GGPD.pos = (sfVector2f)GGP.pos;
        GGPD.frame = 0;
        sfSprite_setRotation(GGPD.dash[0][0], 90);
        sfSprite_setRotation(GGPD.dash[0][2], 90);
        GGPC.dash_enable = false;
        GGPC.on_dash = true;
        if (my_colorcmp(color, sfWhite) || my_colorcmp(color, sfBlue))
            GGP.speed = speed;
    }
    dash_cooldown(global);
}
