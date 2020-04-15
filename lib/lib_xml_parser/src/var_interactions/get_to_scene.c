/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** get_to_scene.c
*/

#include "my.h"
#include "file.h"
#include "xml_parser.h"

size_t get_to_scene(char const **file, char *name_scene)
{
    size_t line = 0;
    bool scene = false;

    while (file[line]) {
        if (get_pos_word_in_str("Scene ", file[line]) != -1 &&
            get_pos_word_in_str("name=", file[line]))
            scene = cmp_var_name(file[line], "name=", name_scene);
        line++;
        if (scene)
            return line;
    }
    return -1;
}

size_t get_end_scene(char const **file, char *name_scene)
{
    size_t begining = get_to_scene(file, name_scene);
    size_t end = begining;

    if (end == (size_t)-1)
        return -1;
    while (file[end]) {
        if (get_pos_word_in_str("/Scene", file[end]) != -1)
            return end;
        end++;
    }
    return -1;
}
