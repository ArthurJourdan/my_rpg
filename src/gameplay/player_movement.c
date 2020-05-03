/*
** EPITECH PROJECT, 2020
** player_movement.c
** File description:
** player movements manager
*/

#include <SFML/Window/Export.h>
#include <SFML/Window/Keyboard.h>
#include <math.h>
#include "my_rpg.h"
#include "sfml_tools.h"

void check_next_pos(global_t *global, sfVector2f *next_pos)
{
    if (GGPC.on_up)
        next_pos->y = (GGP.pos.y - GGP.speed) - GGP.hitbox;
    if (GGPC.on_down)
        next_pos->y = (GGP.pos.y + GGP.speed) + GGP.hitbox;
    if (GGPC.on_left)
        next_pos->x = (GGP.pos.x - GGP.speed) - GGP.hitbox;
    if (GGPC.on_right)
        next_pos->x = (GGP.pos.x + GGP.speed) + GGP.hitbox;
    if (next_pos->x < 0)
        next_pos->x = 0;
    if (next_pos->y < 0)
        next_pos->y = 0;
    if (next_pos->x > GGW)
        next_pos->x = GGW;
    if (next_pos->y > GGH)
        next_pos->y = GGH;
}

void player_movements(global_t *global)
{
    sfVector2f next_pos = {GGP.pos.x, GGP.pos.y};
    sfColor color;
    sfVector2f next;
    sfVector2f relat;

    player_key_pressed(global);
    check_next_pos(global, &next_pos);
    move_check(next_pos, global);
    swap_map(next_pos, global);
    relat = sfV2F{next_pos.x - GGP.pos.x, next_pos.y - GGP.pos.y};
    next = sfV2F{next_pos.x + SIGN(relat.x) * 200,
    next_pos.y + SIGN(relat.y) * 200};
    next = sfV2F{((next.x > 0) ? next.x : 1), ((next.y > 0) ? next.y : 1)};
    next = sfV2F{((next.x < GGW) ? next.x : GGW - 1),
    ((next.y < GGH) ? next.y : GGH - 1)};
    color = sfImage_getPixel(GGLMM[GGLP.y][GGLP.x].coll,
    next.x * (float)1650 / (float)GGW, next.y * (float)990 / (float)GGH);
    player_dash(next_pos, global, color);
    GGP.collider->left = GGP.pos.x;
    GGP.collider->top = GGP.pos.y;
}
