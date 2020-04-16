/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** options.h
*/

#ifndef OPTIONS_H
#define OPTIONS_H

#include "global.h"
#include "gui.h"

void change_all_sounds_volumes(global_t *global, float inc_volume);
void change_all_musics_volumes(global_t *global, float inc_volume);

void change_act_music_volume(global_t *global, float inc_volume);
void change_act_sounds_volumes(global_t *global, float inc_volume);

#endif /* !OPTIONS_H */
