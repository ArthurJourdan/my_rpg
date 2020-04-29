/*
** EPITECH PROJECT, 2020
** enemy 
** File description:
** incldue
*/

#ifndef RPG_ENEMY
#define RPG_ENEMY

#include <SFML/Graphics.h>
#include <stdbool.h>

typedef struct enemy_obj {
    bool obj_status;
    int id;
    int frame;
    int max_hp;
    int hp;
    int damage;
    int *spell_nodes;
    sfVector2f speed;
    sfVector2f pos;
    sfIntRect *collider;
}e_obj_t;

#define E_OBJ_STATUS enemy->obj_status
#define E_ID enemy->id
#define E_FRAME enemy->frame
#define E_POS enemy->pos
#define E_SPEED enemy->speed
#define E_DMG enemy->damage
#define E_SPELL enemy->spell_nodes
#define E_COLLIDER enemy->collider

#endif
