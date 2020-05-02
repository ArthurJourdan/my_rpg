/*
** EPITECH PROJECT, 2020
** init_game.c
** File description:
** initialize game struct
*/

#include "my_rpg.h"

void init_game(global_t *global)
{
    GGW = sfRenderWindow_getSize(GW).x;
    GGH = sfRenderWindow_getSize(GW).y;
    GG.obj = malloc(sizeof(obj_t));
    GG.obj->s_obj = malloc(sizeof(s_obj_t) * 2);
    GG.obj->obj_index = 0;
    init_spell_obj(global);
    init_player(global);
    init_spell_obj_g(global);
    init_layers(global);
}
