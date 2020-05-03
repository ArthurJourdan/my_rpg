/*
** EPITECH PROJECT, 2020
** enemies
** File description:
** clear
*/

#include "a_malloc.h"
#include "my_rpg.h"

void enemy_clear(e_obj_t *enemy)
{
    E_OBJ_STATUS = false;
    E_ID = 0;
    E_FRAME = 0;
    E_FACING = 0;
    E_MHP = 0;
    E_HP = 0;
    E_DMG = 0;
    E_SPELL = NULL;
    E_SPEED = 0;
    E_POS = vec2f(0, 0);
    E_COLLIDER = rect(0, 0, 0, 0);
    return;
}

void enemy_tab_clear(global_t *global)
{
    for (int i = 0; i < 64; i++)
        enemy_clear(GGOE[i]);
    return;
}
