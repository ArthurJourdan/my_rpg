/*
** EPITECH PROJECT, 2020
** my_sfml_lib
** File description:
** get_color_from_str.c
*/

#include "sfml_tools.h"
#include "my.h"

static sfml_colors_t convert_color[] = {
    {{0, 0, 0, 0}, "Transparent"},
    {{0, 0, 0, 255}, "Black"},
    {{125, 125, 125, 255}, "Grey"},
    {{255, 255, 255, 255}, "White"},
    {{255, 0, 0, 255}, "Red"},
    {{0, 255, 0, 255}, "Green"},
    {{0, 0, 255, 255}, "Blue"},
    {{255, 255, 0, 255}, "Yellow"},
    {{0, 255, 255, 255}, "Cyan"},
    {{255, 0, 255, 255}, "Magenta"}
};

sfColor get_color_from_str(char * const str)
{
    if (my_str_is_nothing(str))
        return sfWhite;
    for (size_t a = 0; a < ARRAY_SIZE(convert_color); a++) {
        if (my_strcmp(str, convert_color[a].str_color))
            return convert_color[a].sf_color;
    }
    return sfWhite;
}