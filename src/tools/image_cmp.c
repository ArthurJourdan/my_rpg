/*
** EPITECH PROJECT, 2020
** image_cmp
** File description:
** compare pixels of th sfImage
*/

#include "my_rpg.h"

void move_check(sfVector2f next, global_t *global)
{
    sfVector2f scale = {(float)1650 / (float)GGW, (float)990 / (float)GGH};
    sfVector2f size = {next.x * scale.x, next.y * scale.y};
    sfColor color = sfImage_getPixel(GGLMM[GGLP.y][GGLP.x].coll, size.x, size.y);

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

void swap_map(sfVector2f next, global_t *global)
{
    sfVector2f scale = {(float)1650 / (float)GGW, (float)990 / (float)GGH};
    sfVector2f size = {next.x * scale.x, next.y * scale.y};
    sfColor color = sfImage_getPixel(GGLMM[GGLP.y][GGLP.x].coll, size.x, size.y);

    if (!my_colorcmp(color, sfRed))
        return;
    if (GGP.pos.x > GGW - 300 && GGLP.x < 6 && GGLMM[GGLP.y][GGLP.x + 1].is_open) {
        GGP.pos.x = 100;
        GGLP.x++;
    } else if (GGP.pos.x < 300 && GGLP.x > 0 && GGLMM[GGLP.y][GGLP.x - 1].is_open) {
        GGP.pos.x = GGW - 100;
        GGLP.x--;
    }
    if (GGP.pos.y > GGH - 300 && GGLP.y < 6 && GGLMM[GGLP.y + 1][GGLP.x].is_open) {
        GGP.pos.y = 100;
        GGLP.y++;
    } else if (GGP.pos.y < 300 && GGLP.y > 0 && GGLMM[GGLP.y - 1][GGLP.x].is_open) {
        GGP.pos.y = GGH - 100;
        GGLP.y--;
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
    sfVector2f scale = {(float)1650 / (float)GGW, (float)990 / (float)GGH};
    sfVector2f size = {next.x * scale.x, next.y * scale.y};
    sfColor color = sfImage_getPixel(GGLMM[GGLP.y][GGLP.x].coll, size.x, size.y);
    float speed = GGP.speed * 4;

    if (sfKeyboard_isKeyPressed(GGPC.dash) && GGPC.dash_enable &&
        my_colorcmp(dash_color, sfWhite)) {
        sfClock_restart(GGPC.dash_clock);
        sfClock_restart(GGPC.clock);
        GGPD.pos = (sfVector2f)GGP.pos;
        GGPD.frame = 0;
        sfSprite_setRotation(GGPD.dash[0][0], 90);
        GGPC.dash_enable = false;
        GGPC.on_dash = true;
        if (my_colorcmp(color, sfWhite) || my_colorcmp(color, sfBlue))
            GGP.speed = speed;
    }
    dash_cooldown(global);
}