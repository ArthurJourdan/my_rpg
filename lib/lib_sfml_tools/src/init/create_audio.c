/*
** EPITECH PROJECT, 2020
** sfml lib
** File description:
** set_audio.c
*/

#include "sfml_tools.h"
#include "file.h"

sfSound *create_sound(sfSound *sound, char *file, float volume, bool loop)
{
    sfSoundBuffer *sound_buffer = NULL;

    if (!sound)
        sound = sfSound_create();
    if (!sound)
        return NULL;
    if (is_file_openable(file)) {
        sound_buffer = sfSoundBuffer_createFromFile(file);
        if (!sound_buffer)
            return sound;
        sfSound_setBuffer(sound, sound_buffer);
        if (volume >= 0) {
            sfSound_setVolume(sound, volume);
        sfSound_setLoop(sound, loop);
        }
    }
    return sound;
}

sfMusic *create_music(sfMusic *music, char *file, float volume, bool loop)
{
    if (is_file_openable(file)) {
        if (!music)
            music = sfMusic_createFromFile(file);
        if (!music)
            return NULL;
        if (volume >= 0) {
            sfMusic_setVolume(music, volume);
        }
        sfMusic_setLoop(music, loop);
    }
    return music;
}