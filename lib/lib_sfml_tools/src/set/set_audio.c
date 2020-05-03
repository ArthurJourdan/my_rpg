/*
** EPITECH PROJECT, 2020
** my_lib_sfml
** File description:
** set_audio.c
*/

#include "sfml_tools.h"
#include <stdbool.h>

static bool check_volume(float volume)
{
    if (volume < 0)
        return false;
    if (volume > 100)
        return false;
    return true;
}

void set_sound_volume(sfSound *sound, float volume)
{
    if (!sound)
        return;
    if (check_volume(volume)) {
        sfSound_setVolume(sound, volume);
    }
}

void set_music_volume(sfMusic *music, float volume)
{
    if (!music)
        return;
    if (check_volume(volume)) {
        sfMusic_setVolume(music, volume);
    }
}

void change_sound_volume(sfSound *sound, float increase)
{
    float fut_volume = 0;

    if (!sound)
        return;
    fut_volume = sfSound_getVolume(sound) + increase;
    if (check_volume(fut_volume)) {
        sfSound_setVolume(sound, fut_volume);
    }
}

void change_music_volume(sfMusic *music, float increase)
{
    float fut_volume = 0;

    if (!music)
        return;
    fut_volume = sfMusic_getVolume(music) + increase;
    if (check_volume(fut_volume)) {
        sfMusic_setVolume(music, fut_volume);
    }
}
