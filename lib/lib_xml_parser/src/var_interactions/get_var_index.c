/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** get_var_index.c
*/

#include "my.h"
#include "file.h"
#include "xml_parser.h"

int get_var_index(char const *line, char **list_names)
{
    int index = 0;
    char *name_var = NULL;

    name_var = cpy_var_name(" name=", line);
    for (; list_names[index]; index++) {
        if (my_strcmp(name_var, list_names[index])) {
            free(name_var);
            return index;
        }
    }
    return -1;
}