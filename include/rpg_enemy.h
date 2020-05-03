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
    int facing;
    int frame;
    int max_hp;
    int hp;
    int damage;
    int *spell_nodes;
    float speed;
    sfTime movet;
    sfVector2f pos;
    sfIntRect *collider;
}e_obj_t;

#define E_OBJ_STATUS enemy->obj_status
#define E_ID enemy->id
#define E_FRAME enemy->frame
#define E_FACING enemy->facing
#define E_POS enemy->pos
#define E_SPEED enemy->speed
#define E_DMG enemy->damage
#define E_SPELL enemy->spell_nodes
#define E_COLLIDER enemy->collider
#define E_MOVET enemy->movet
#define E_HP enemy->hp
#define E_MHP enemy->max_hp
#define E_CLOCK global->game->obj->e_clock

#define GGOE global->game->obj->e_obj
#define E_DICT global->game->dict->enemy_dict

#define vec2f(x, y) (sfVector2f){(x), (y)}
#defins msec(x) (x).microsends / 1000

#endif
