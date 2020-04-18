/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** set_music.c
*/

#include "my.h"
#include "xml_parser.h"
#include "sfml_tools.h"

sfMusic *set_any_music(char const *line)
{
    sfMusic *music = NULL;
    char *filepath = cpy_var_name(" audio=", line);
    float volume = cpy_var_float(" volume=", line);
    bool loop = cpy_var_bool(" loop=", line);

    if (filepath) {
        music = create_music(NULL, filepath, volume, loop);
        free_char_to_null(filepath);
    }
    return music;
}

void set_music(char const *line, gui_t *scene_list, size_t scene_nb,
N_U sfRenderWindow *window)
{
    char *filepath = cpy_var_name(" audio=", line);
    float volume = cpy_var_float(" volume=", line);
    bool loop = cpy_var_bool(" loop=", line);

    if (filepath) {
        SL[scene_nb]->music = create_music(NULL, filepath, volume, loop);
        free(filepath);
    }
}
