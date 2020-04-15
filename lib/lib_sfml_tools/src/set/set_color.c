/*
** EPITECH PROJECT, 2020
** sfml_lib
** File description:
** set_color.c
*/

#include "sfml_tools.h"

void set_rectshape_color(sfRectangleShape *rectshape,
sfColor in, sfColor out, float outline_thickness)
{
    if (!rectshape)
        return;
    if (in.a != 0)
        sfRectangleShape_setFillColor(rectshape, in);
    sfRectangleShape_setOutlineColor(rectshape, out);
    if (outline_thickness >= 0)
        sfRectangleShape_setOutlineThickness(rectshape, outline_thickness);
}