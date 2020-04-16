/*
** EPITECH PROJECT, 2020
** PSU_my_rpg
** File description:
** change_sounds_volume.c
*/

#include "global.h"
#include "gui.h"
#include "sfml_tools.h"
#include "shorting_defines.h"

static void change_volumes_buttons(button_t **buttons, float inc_volume)
{
    for (size_t a = 0; buttons[a]; a++) {
        change_sound_volume(buttons[a]->sound, inc_volume);
    }
}

static void change_volumes_sound_scene(gui_t *scene_list, float inc_volume)
{
    for (size_t a = 0; a <= TUTO; a++) {
        if (!SL[a] || !SL[a]->sound)
            continue;
        change_volumes_buttons(SL[a]->buttons, inc_volume);
        change_sound_volume(SL[a]->sound, inc_volume);
    }
}

void change_all_sounds_volumes(global_t *global, float inc_volume)
{
    change_volumes_sound_scene(GS, inc_volume);
}

void change_act_sounds_volumes(global_t *global, float inc_volume)
{
    change_volumes_buttons(SC_B, inc_volume);
    change_sound_volume(SC_S, inc_volume);
}