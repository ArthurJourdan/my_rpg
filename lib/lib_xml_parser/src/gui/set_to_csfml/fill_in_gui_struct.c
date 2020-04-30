/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** fill_in_game_struct.c
*/

#include "my.h"
#include "gui.h"
#include "shorting_defines.h"
#include "file.h"
#include "xml_parser.h"

static const gui_functions_t set_functions[] = {
    {"Image ", &set_image},
    {"Button ", &set_button},
    {"Music ", &set_music},
    {"Text ", &set_text},
    {"Sound ", &set_sound}
};

static void check_line(char const *line, gui_t *sc_list, size_t scene_nb,
sfRenderWindow *window)
{
    int pos = 0;

    for (size_t b = 0; b < ARRAY_SIZE(set_functions); b++) {
        pos = get_pos_word_in_str(set_functions[b].type, line);
        if (pos != -1) {
            set_functions[b].ptr(line + pos, sc_list, scene_nb, window);
        }
    }
}

void fill_in_basic(char const **file, gui_t *scene_list)
{
    scene_list->index = HOME;
}

void fill_in_gui_struct(char const **file, gui_t *scene_list,
sfRenderWindow *window)
{
    char *which_scene = NULL;
    size_t scene_nb = 0;

    fill_in_basic(file, scene_list);
    for (size_t line = 0; file[line]; line++) {
        if (get_pos_word_in_str("Scene", file[line]) != -1 &&
            get_pos_word_in_str("name=", file[line]) != -1) {
            if (which_scene) {
                which_scene = free_char_to_null(which_scene);
            }
            which_scene = cpy_var_name("name=", file[line]);
            scene_nb = scene_chooser(scene_list, which_scene);
        } else {
            check_line(file[line], scene_list, scene_nb, window);
        }
    }
    if (which_scene) {
        which_scene = free_char_to_null(which_scene);
    }
}
