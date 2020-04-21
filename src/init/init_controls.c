/*
** EPITECH PROJECT, 2020
** init_controls.c
** File description:
** initialize keyboard controls
*/

#include "my_rpg.h"

void init_controls(controls_t *controls)
{
    controls->on_up = false;
    controls->on_left = false;
    controls->on_down = false;
    controls->on_right = false;
    controls->on_sprint = false;
    controls->up = sfKeyZ;
    controls->left = sfKeyQ;
    controls->down = sfKeyS;
    controls->right = sfKeyD;
    controls->sprint = sfKeyLShift;
    controls->left_spell = sfKeyA;
    controls->right_spell = sfKeyE;
    controls->move_nb = 0;
    controls->clock = sfClock_create();
}
