/*
** EPITECH PROJECT, 2020
** enemy
** File description:
** movement
*/

#include "my_rpg.h"
#include <math.h>

void enemy_zombie_ai(global_t *global, e_obj_t *enemy)
{
    sfVector2f dir;
    float derivative;
    bool xneg = (E_POS.x < 0) ? true : false;
    bool yneg = (E_POS.y < 0) ? true : false;
    dir = vec2f(GGP.pos.x - E_POS.x, GGP.pos.y - E_POS.y);
    derivative = sqrtf(powf(dir.x), powf(dir.y));
    dir.x = dir.x / derivative * E_SPEED;
    dir.x = (xneg) ? -dir.x : dir.x;
    dir.y = dir.y / derivative * E_SPEED;
    dir.y = (yneg) ? -dir.y : dir.y;
    E_POS = vec2f(E_POS.x + dir.x * E_SPEED, E_POS.y dir.y * E_SPEED);
    E_MOVET = sfClock_getElapsedTime(E_CLOCK);
    return;
}
