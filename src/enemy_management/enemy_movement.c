/*
** EPITECH PROJECT, 2020
** enemy
** File description:
** movement
*/

#include "my_rpg.h"
#include <math.h>

static void set_enemy_facing(e_obj_t *enemy, sfVector2f dir)
{
    if (ABS(dir.x) < ABS(dir.y)) {
        if (dir.y < 0)
            E_FACING = 3;
        else
            E_FACING = 0;
    } else {
        if (dir.x < 0)
            E_FACING = 1;
        else
            E_FACING = 2;
    }
    return;
}

void enemy_zombie_ai(global_t *global, e_obj_t *enemy)
{
    sfVector2f dir;
    float derivative;
    sfTime time = sfClock_getElapsedTime(E_CLOCK);
    float timem = msec(time) - msec(E_MOVET);

    dir = vec2f(GGP.pos.x - E_POS.x, GGP.pos.y - E_POS.y);
    set_enemy_facing(enemy, dir);
    derivative = sqrtf(powf(dir.x, 2) + powf(dir.y, 2));
    dir.x = dir.x / derivative * E_SPEED * (timem / 1000);
    dir.y = dir.y / derivative * E_SPEED * (timem / 1000);
    E_POS = vec2f(E_POS.x + dir.x, E_POS.y + dir.y);
    E_COLLIDER.left = E_POS.x;
    E_COLLIDER.top = E_POS.y;
    E_MOVET = sfClock_getElapsedTime(E_CLOCK);
    return;
}
