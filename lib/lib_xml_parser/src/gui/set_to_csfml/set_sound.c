/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** set_sound.c
*/

#include "my.h"
#include "gui.h"
#include "shorting_defines.h"
#include "xml_parser.h"
#include "sfml_tools.h"

sfSound *set_any_sound(char const *line)
{
    char *sound_name = cpy_var_name(" sound=", line);
    int volume = cpy_var_int(" volume=", line);
    sfSound *sound = NULL;

    if (sound_name) {
        sound = create_sound(NULL, sound_name, volume);
        free(sound_name);
    }
    return sound;
}

void set_sound(char const *line, gui_t *scene_list, size_t scene_nb,
N_U sfRenderWindow *window)
{
    char *sound_name = NULL;
    char *volume = NULL;
    sfSoundBuffer *sound_buffer = NULL;

    sound_name = cpy_var_name("audio=", line);
    if (sound_name) {
        sound_buffer = sfSoundBuffer_createFromFile(sound_name);
        SL[scene_nb]->sound = sfSound_create();
        sfSound_setBuffer(SL[scene_nb]->sound, sound_buffer);
        free(sound_name);
        volume = cpy_var_name("volume=", line);
        if (volume && my_str_is_num(volume)) {
            sfSound_setVolume(SL[scene_nb]->sound, my_getnbr(volume));
            free(volume);
        }
    }
}
