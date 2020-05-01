/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** get_size.c
*/

#include "my.h"
#include "gui.h"
#include "shorting_defines.h"
#include "xml_parser.h"

sfVector2f get_dimensions(char const *line)
{
    sfVector2f size = {0};

    size.x = cpy_var_int(" width=", line);
    size.y = cpy_var_int(" height=", line);
    return size;
}

sfVector2f get_scale(char const *line)
{
    sfVector2f size = {0};

    size.x = cpy_var_float(" scale_x=", line);
    size.y = cpy_var_float(" scale_y=", line);
    return size;
}