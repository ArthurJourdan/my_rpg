/*
** EPITECH PROJECT, 2020
** init_controls.c
** File description:
** initialize keyboard controls
*/

#include "my_rpg.h"

void init_controls(global_t *global)
{
    GGPC.on_up = false;
    GGPC.on_left = false;
    GGPC.on_down = false;
    GGPC.on_right = false;
    GGPC.on_dash = false;
    GGPC.dash_enable = true;
    GGPC.up = sfKeyZ;
    GGPC.left = sfKeyQ;
    GGPC.down = sfKeyS;
    GGPC.right = sfKeyD;
    GGPC.dash = sfKeySpace;
    GGPC.left_spell = sfKeyA;
    GGPC.right_spell = sfKeyE;
    GGPC.move_nb = 0;
    GGPC.dash_clock = sfClock_create();
    GGPC.clock = sfClock_create();
}
