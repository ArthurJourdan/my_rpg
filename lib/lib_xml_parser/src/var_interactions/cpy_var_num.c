/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** cpy_var_num.c
*/

#include "my.h"
#include "file.h"

int cpy_var_int(char var_name[], char const *line)
{
    int pos = 0;
    char *var = NULL;
    int nb = 0;

    pos = get_pos_word_end_in_str(var_name, line);
    if (pos != -1)
        var = my_str_cpy_quotation((char *)line + pos - 2);
    if (var && my_str_is_num(var)) {
        nb = my_getnbr(var);
        free(var);
    }
    return nb;
}

int cpy_var_int_double_arr(char ward[], char var_name[], char *file[])
{
    size_t pos = get_pos_word_in_arr(ward, (char const **)file);
    int nb = 0;

    if (pos == -1)
        return 0;
    nb = cpy_var_int(var_name, file[pos]);
    return nb;
}

float cpy_var_float(char var_name[], char const *line)
{
    ssize_t pos = 0;
    char *var = NULL;
    float nb = 0;

    pos = get_pos_word_end_in_str(var_name, line);
    if (pos != -1)
        var = my_str_cpy_quotation((char *)line + pos - 2);
    if (var && my_str_is_float(var)) {
        nb = my_getfloat(var);
        free(var);
    }
    return nb;
}

bool cpy_var_bool(char var_name[], char const *line)
{
    int pos = get_pos_word_end_in_str(var_name, line);
    char *var = NULL;
    bool yes_or_no = false;

    if (pos != -1)
        var = my_str_cpy_quotation((char *)line + pos - 2);
    if (var) {
        if (my_strcmp(var, "true") || my_strcmp(var, "yes") ||
my_strcmp(var, "oui") || my_strcmp(var, "alright")) {
            yes_or_no = true;
        }
        free(var);
    }
    return yes_or_no;
}