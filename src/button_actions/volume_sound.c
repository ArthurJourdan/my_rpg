/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** sound_volume.c
*/

#include "global.h"
#include "options.h"
#include "options.h"

void volume_sounds_up(global_t *global)
{
    change_act_sounds_volumes(global, 2.0f);
}

void volume_sounds_down(global_t *global)
{
    change_act_sounds_volumes(global, -2.0f);
}

void volume_all_sounds_up(global_t *global)
{
    change_all_sounds_volumes(global, 2.0f);
}

void volume_all_sounds_down(global_t *global)
{
    change_all_sounds_volumes(global, -2.0f);
}
