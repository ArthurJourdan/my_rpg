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
    float volume = cpy_var_float(" volume=", line);
    bool loop = cpy_var_bool(" loop=", line);
    sfSound *sound = NULL;

    if (sound_name) {
        sound = create_sound(NULL, sound_name, volume, loop);
        free(sound_name);
    }
    return sound;
}

void set_sound(char const *line, gui_t *scene_list, size_t scene_nb,
N_U sfRenderWindow *window)
{
    char *sound_name = cpy_var_name(" audio=", line);
    float volume = cpy_var_float(" volume=", line);
    bool loop = cpy_var_bool(" loop=", line);

    if (sound_name) {
        SL[scene_nb]->sound = create_sound(NULL, sound_name, volume, loop);
        free(sound_name);
    }
}
