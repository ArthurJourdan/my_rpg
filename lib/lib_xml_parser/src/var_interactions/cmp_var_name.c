/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** cmp_id_name.c
*/

#include "my.h"
#include "file.h"
#include "xml_parser.h"

bool cmp_var_name(char const *line, char const *var, char const *name)
{
    int pos = get_pos_word_in_str(var, line);
    char *var_name = NULL;

    if (pos != -1) {
        var_name = cpy_var_name((char *)var, line);
        if (!var_name)
            return false;
        if (my_strcmp(var_name, name)) {
            free(var_name);
            return true;
        }
        free(var_name);
    }
    return false;
}
