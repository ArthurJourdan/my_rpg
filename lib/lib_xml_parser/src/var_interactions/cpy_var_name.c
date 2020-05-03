/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** cpy_var_name.c
*/

#include "my.h"
#include "file.h"

char *cpy_var_name(char var_name[], char const *line)
{
    int pos = 0;
    char *var = NULL;

    pos = get_pos_word_end_in_str(var_name, line);
    if (pos != -1)
        var = my_str_cpy_quotation((char *)line + pos - 2);
    return var;
}

char *cpy_var_name_double_arr(char ward[], char var_name[], char *file[])
{
    char *var = NULL;
    size_t pos = get_pos_word_in_arr(ward, (char const **)file);

    if (pos == -1)
        return NULL;
    var = cpy_var_name(var_name, file[pos]);
    return var;
}