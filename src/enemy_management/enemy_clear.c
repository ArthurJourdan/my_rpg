/*
** EPITECH PROJECT, 2020
** enemies
** File description:
** clear
*/

#include "a_malloc.h"
#include "my_rpg.h"

void enemy_clear(global_t *global, int i)
{
    G_E_OBJ[i]->obj_status = false;
    G_E_OBJ[i]->id = 0;
    G_E_OBJ[i]->frame = 0;
    G_E_OBJ[i]->max_hp = 0;
    G_E_OBJ[i]->hp = 0;
    G_E_OBJ[i]->damage = 0;
    G_E_OBJ[i]->spell_nodes = NULL;
    G_E_OBJ[i]->speed = {0};
    G_E_OBJ[i]->pos = {0};
    G_E_OBJ[i]->collider = NULL;
    return;
}

void enemy_tab_clear(global_t *global)
{
    for (int i = 0; i < 64; i++)
        enemy_clear(global, i);
    return;
}
