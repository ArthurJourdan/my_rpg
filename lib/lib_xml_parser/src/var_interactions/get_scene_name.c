/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** get_scene_name.c
*/

#include "file.h"
#include "my.h"
#include "xml_parser.h"

void get_scene_name(char const *line, char *scene_name)
{
    if (get_pos_word_in_str("Scene", line) != -1 &&
        get_pos_word_in_str("name=", line) != -1) {
        if (scene_name)
            free(scene_name);
        scene_name = cpy_var_name("name=", line);
    }
}

bool is_scene_changed(char const *line, char *scene_name)
{
    if (get_pos_word_in_str("Scene", line) != -1 &&
        get_pos_word_in_str("name=", line) != -1) {
        return true;
    }
    return false;
}
