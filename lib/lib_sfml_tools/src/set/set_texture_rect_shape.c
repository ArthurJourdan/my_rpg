/*
** EPITECH PROJECT, 2020
** my_lib_sfml
** File description:
** set_texture_rect_shape.c
*/

#include "sfml_tools.h"

void set_texture_rect_shape(sfRectangleShape *rect_shape,
 unsigned short nb_animations, size_t size_tot)
{
    size_t offset = size_tot / nb_animations;
    sfIntRect rectangle = sfRectangleShape_getTextureRect(rect_shape);

    rectangle.width = offset;
    if (rectangle.left < size_tot)
        rectangle.left += offset;
    else
        rectangle.left = 0;
    sfRectangleShape_setTextureRect(rect_shape, rectangle);
}