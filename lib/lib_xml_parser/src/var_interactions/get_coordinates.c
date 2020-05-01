/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** get_coordinates.c
*/

#include "my.h"
#include "gui.h"
#include "shorting_defines.h"
#include "xml_parser.h"

sfVector2f get_coordinates(char const *line)
{
    sfVector2f pos = {0, 0};

    pos.x = (float)cpy_var_int(" x=", line);
    pos.y = (float)cpy_var_int(" y=", line);
    return pos;
}
