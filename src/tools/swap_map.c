/*
** EPITECH PROJECT, 2020
** image_cmp
** File description:
** compare pixels of th sfImage
*/

#include "my_rpg.h"

static void generate_enemies(global_t *global, sfColor color)
{
    if (GGLMM[GGLP.y][GGLP.x].is_enemies) {
        if (GGLMM[GGLP.y][GGLP.x].spawn &&
            my_colorcmp(color, sfRed)) {
            enemy_tab_clear(global);
            enemy_generate_hord(global);
            GGLMM[GGLP.y][GGLP.x].spawn = false;
        }
    } else
        enemy_tab_clear(global);
}

static void check_left_right(global_t *global)
{
    if (GGP.pos.x > GGW - 300 && GGLP.x < (GGM - 1) &&
        GGLMM[GGLP.y][GGLP.x + 1].is_open) {
        GGP.pos.x = 100;
        GGLP.x++;
    } else if (GGP.pos.x < 300 && GGLP.x > 0 &&
        GGLMM[GGLP.y][GGLP.x - 1].is_open) {
        GGP.pos.x = GGW - 100;
        GGLP.x--;
    }
}

static void check_up_down(global_t *global)
{
    if (GGP.pos.y > GGH - 300 && GGLP.y < (GGM - 1) &&
        GGLMM[GGLP.y + 1][GGLP.x].is_open) {
        GGP.pos.y = 100;
        GGLP.y++;
    } else if (GGP.pos.y < 300 && GGLP.y > 0 &&
        GGLMM[GGLP.y - 1][GGLP.x].is_open) {
        GGP.pos.y = GGH - 100;
        GGLP.y--;
    }
}

void swap_map(sfVector2f next, global_t *global)
{
    sfColor color = get_pixel_color(next, global);

    if (!my_colorcmp(color, sfRed))
        return;
    check_left_right(global);
    check_up_down(global);
    generate_enemies(global, color);
}
