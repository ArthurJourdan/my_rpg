/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** action_button.c
*/

#include "my.h"
#include "gui.h"
#include "shorting_defines.h"
#include "global.h"

int action_button(global_t *global, int button_nb)
{
    size_t which_act = 0;

    if (SC_B[button_nb]->sound)
        sfSound_play(SC_B[button_nb]->sound);
    if (SC_B[button_nb]->action)
    SC_B[button_nb]->action(global);

    return 0;
}
