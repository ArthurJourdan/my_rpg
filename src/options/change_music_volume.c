/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** change_music_volumes.c
*/

#include "global.h"
#include "gui.h"
#include "sfml_tools.h"

void change_all_musics_volumes(global_t *global, float inc_volume)
{
    for (size_t a = 0; a <= TUTO; a++) {
        if (!GS->scenes[a] || !GS->scenes[a]->music)
            continue;
        change_music_volume(GS->scenes[a]->music, inc_volume);
    }
}

void change_act_music_volume(global_t *global, float inc_volume)
{
    if (GS->scenes[ACT]->music)
        change_music_volume(GS->scenes[ACT]->music, inc_volume);
}