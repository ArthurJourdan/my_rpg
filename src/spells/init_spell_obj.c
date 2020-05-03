/*
** EPITECH PROJECT, 2020
** init_spell_obj
** File description:
** inits the spell obj when activated
*/

#include "my_rpg.h"

void init_spell_obj(global_t *global)
{
    for (int i = 0; i < 2; i++) {
        GGO->s_obj[i].obj_status = false;
        GGO->s_obj[i].activation_radius = 0;
        GGO->s_obj[i].id = -1;
        GGO->s_obj[i].frame = 0;
        GGO->s_obj[i].side = 0;
        GGO->s_obj[i].type = -1;
        GGO->s_obj[i].category = -1;
        GGO->s_obj[i].activation_radius = 0;
        GGO->s_obj[i].starting_pos = (sfVector2f){0};
        GGO->s_obj[i].speed = (sfVector2f){0};
        GGO->s_obj[i].pos = (sfVector2f){0};
        GGO->s_obj[i].collider = malloc(sizeof(sfIntRect));
        GGO->s_obj[i].range = 0;
        GGO->s_obj[i].dir = 1;
    }
}
