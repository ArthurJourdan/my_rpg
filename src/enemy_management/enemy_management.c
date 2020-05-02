/*
** EPITECH PROJECT, 2020
** enemy_management.c
** File description:
** aa
*/

#include "my_rpg.h"

static void manage_enemy(global_t *global, e_obj_t *enemy)
{
    sfTime time = sfClock_getElapsedTime(E_CLOCK);
    if (E_HP <= 0) {
        enemy_clear(enemy);
        return;
    }
    check_enemy_collision(global, enemy);
    enemy_zombie_ai(global, enemy);
    if (msec(time) - msec(E_FRAMET) > 200) {
        E_FRAMET = sfClock_getElapsedTime(E_CLOCK);
        E_FRAME = (E_DICT[E_ID]->sprite[E_FACING][E_FRAME + 1] != NULL)
        ? E_FRAME + 1 : 0;
    }
    return;
}

void enemy_management(global_t *global)
{
    for (int i = 0; i < 64; i++) {
        if (GGOE[i]->obj_status == true) {
            manage_enemy(global, GGOE[i]);
        }
    }
    return;
}
