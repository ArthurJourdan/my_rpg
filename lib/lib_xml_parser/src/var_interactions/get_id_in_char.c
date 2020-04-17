/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** get_id_in_char.c
*/

#include "xml_parser.h"

char get_id(char const *line)
{
    if (cmp_var_name(line, "id=", "tower"))
        return 't';
    if (cmp_var_name(line, "id=", "enemy"))
        return 'e';
    return '\0';
}
