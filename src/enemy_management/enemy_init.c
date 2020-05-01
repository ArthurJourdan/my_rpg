/*
** EPITECH PROJECT, 2020
** enemies
** File description:
** init
*/

#include "a_malloc.h"
#include "my_rpg.h"

void enemy_tab_init(global_t *global)
{
    //G_E_OBJ = a_malloc(sizeof(e_obj_t *) * 64 | A_LIST(1));
    E_CLOCK = sfClock_create();
    
    for (int i = 0; i < 64; i++) {
        G_E_OBJ[i] = a_malloc(sizeof(e_obj_t) | A_LIST(1));
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
    }
    return;
}

void enemy_init(game_t *global, int id, sfVector2f pos)
{
    int i = 0;

    for (i = 0; G_E_OBJ[i]->obj_satus == true; i++);
    G_E_OBJ[i]->obj_status = true;
    G_E_OBJ[i]->id = id;
    G_E_OBJ[i]->frame = 0;
    G_E_OBJ[i]->max_hp = G_E_DICT[id]->hp;
    G_E_OBJ[i]->hp = G_E_OBJ[i]->max_hp;
    G_E_OBJ[i]->spell_nodes = G_E_DICT[id]->spell_nodes;
    G_E_OBJ[i]->speed = {0};
    G_E_OBJ[i]->pos = pos;
    G_E_OBJ[i]->collider = G_E_DICT[id]->collider;
    return;
}
