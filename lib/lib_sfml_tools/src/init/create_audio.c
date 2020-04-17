/*
** EPITECH PROJECT, 2020
** sfml lib
** File description:
** set_audio.c
*/

#include "sfml_tools.h"
#include "file.h"

sfSound *create_sound(sfSound *sound, char *filepath, float volume)
{
    sfSoundBuffer *sound_buffer = NULL;

    if (!sound)
        sound = sfSound_create();
    if (!sound)
        return NULL;
    if (filepath && is_file_openable(filepath)) {
        sound_buffer = sfSoundBuffer_createFromFile(filepath);
        if (!sound_buffer)
            return sound;
        sfSound_setBuffer(sound, sound_buffer);
        sfSoundBuffer_destroy(sound_buffer);
        if (volume >= 0) {
            sfSound_setVolume(sound, volume);
        }
    }
    return sound;
}