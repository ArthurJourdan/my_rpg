/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** volume.c
*/

#include "global.h"
#include "options.h"

global_t *volume_music_up(global_t *global)
{
    change_act_music_volume(global, 2.0f);
    return global;
}

global_t *volume_music_down(global_t *global)
{
    change_act_music_volume(global, -2.0f);
    return global;
}

global_t *volume_all_musics_up(global_t *global)
{
    change_all_musics_volumes(global, 2.0f);
    return global;
}

global_t *volume_all_musics_down(global_t *global)
{
    change_all_musics_volumes(global, -2.0f);
    return global;
}