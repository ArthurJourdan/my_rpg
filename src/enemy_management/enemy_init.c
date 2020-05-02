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
    E_CLOCK = sfClock_create();
    GGOE = a_malloc(sizeof(e_obj_t *) * 64 | A_LIST(1));
    for (int i = 0; i < 64; i++) {
        GGOE[i] = a_malloc(sizeof(e_obj_t) | A_LIST(1));
        GGOE[i]->obj_status = false;
        GGOE[i]->id = 0;
        GGOE[i]->frame = 0;
        GGOE[i]->facing = 0;
        GGOE[i]->max_hp = 0;
        GGOE[i]->hp = 0;
        GGOE[i]->damage = 0;
        GGOE[i]->spell_nodes = NULL;
        GGOE[i]->speed = 0;
        GGOE[i]->pos = vec2f(0, 0);
        //GGOE[i]->collider = NULL;
    }
    return;
}

// void enemy_init_cod(global_t *global, int i, int id)
// {
//     GGOE[i]->collider = malloc(sizeof(sfIntRect));
//     GGOE[i]->collider->height = E_DICT[id]->hitbox.height;
//     GGOE[i]->collider->width = E_DICT[id]->hitbox.width;
//     GGOE[i]->collider->left = E_DICT[id]->hitbox.left;
//     GGOE[i]->collider->top = E_DICT[id]->hitbox.top;
// }

void enemy_init(global_t *global, int id, sfVector2f pos)
{
    int i = 0;

    if (!GGEN)
        return;
    for (i = 0; GGOE[i]->obj_status == true; i++);
    GGOE[i]->obj_status = true;
    GGOE[i]->id = id;
    GGOE[i]->frame = 0;
    GGOE[i]->facing = 0;
    GGOE[i]->max_hp = E_DICT[id]->life;
    GGOE[i]->hp = GGOE[i]->max_hp;
    GGOE[i]->damage = E_DICT[id]->damage;
    GGOE[i]->spell_nodes = E_DICT[id]->spell_list;
    GGOE[i]->speed = E_DICT[id]->move_speed;
    GGOE[i]->collider = E_DICT[id]->hitbox;
    GGOE[i]->pos = pos;
    GGOE[i]->movet = sfClock_getElapsedTime(E_CLOCK);
    GGOE[i]->framet = sfClock_getElapsedTime(E_CLOCK);
    return;
}

void enemy_generate_hord(global_t *global)
{
    sfVector2u s = sfRenderWindow_getSize(GW);
    sfVector2f pos;
    for (int i = 0; i < 3; i++) {
        pos = vec2f(rand() % s.x, rand() % s.y);
        enemy_init(global, 0, pos);
    }
    return;
}
