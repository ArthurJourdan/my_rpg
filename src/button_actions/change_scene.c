/*
** EPITECH PROJECT, 2020
** MUL_
** File description:
** change_scene.c
*/

#include "gui.h"
#include "shorting_defines.h"

void change_scene(struct gui *scene_list, int scene_nb)
{
    if (!SL[scene_nb])
        return;
    if (SL[ACT_S]->music)
        sfMusic_pause(SL[ACT_S]->music);
    ACT_S = scene_nb;
    if (SL[ACT_S]->music)
        sfMusic_play(SL[ACT_S]->music);
    if (SL[ACT_S]->sound)
        sfSound_play(SL[ACT_S]->sound);
}
