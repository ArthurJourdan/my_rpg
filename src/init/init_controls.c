/*
** EPITECH PROJECT, 2020
** init_controls.c
** File description:
** initialize keyboard controls
*/

#include "my_rpg.h"

void init_controls(controls_t *controls)
{
    printf("controls1\n");
    controls->up = 10;
    printf("controls2\n");
    controls->left = sfKeyQ;
    printf("controls3\n");
    controls->down = sfKeyS;
    printf("controls4\n");
    controls->right = sfKeyD;
    printf("controls5\n");
    controls->left_spell = sfKeyA;
    printf("controls6\n");
    controls->right_spell = sfKeyE;
}
