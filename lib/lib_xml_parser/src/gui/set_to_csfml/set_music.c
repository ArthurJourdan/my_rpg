/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** set_music.c
*/

#include "my.h"
#include "xml_parser.h"

sfMusic *set_any_music(char const *line)
{
    char *info = NULL;
    int volume = 0;
    sfMusic *music = NULL;
    bool loop = false;

    info = cpy_var_name(" audio=", line);
    if (info) {
        music = sfMusic_createFromFile(info);
        free_char_to_null(info);
        volume = cpy_var_int(" volume=", line);
        sfMusic_setVolume(music, volume);
        loop = cpy_var_bool(" loop=", line);
        if (loop) {
            sfMusic_setLoop(music, sfTrue);
        }
    }
    return music;
}

void set_music(char const *line, gui_t *scene_list, size_t scene_nb,
N_U sfRenderWindow *window)
{
    char *music_name = NULL;
    char *volume = NULL;
    char *music_loop = NULL;

    music_name = cpy_var_name("audio=", line);
    if (music_name) {
        SL[scene_nb]->music = sfMusic_createFromFile(music_name);
        free(music_name);
        volume = cpy_var_name("volume=", line);
        if (volume && my_str_is_num(volume)) {
            sfMusic_setVolume(SL[scene_nb]->music, my_getnbr(volume));
            free(volume);
        }
        music_loop = cpy_var_name("loop=", line);
        if (music_loop) {
            if (my_strcmp(music_loop, "true"))
                sfMusic_setLoop(SL[scene_nb]->music, sfTrue);
            free(music_loop);
        }
    }
}
