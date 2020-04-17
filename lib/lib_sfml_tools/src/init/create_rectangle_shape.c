/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** create_rectangle_shape.c
*/

#include "sfml_tools.h"
#include "my.h"

sfRectangleShape *create_rectshape(sfRectangleShape *rect, sfVector2f size)
{
    if (!rect)
        rect = sfRectangleShape_create();
    if (!rect)
        return NULL;
    if (size.x >= 0 && size.y >= 0)
        sfRectangleShape_setSize(rect, size);
    return rect;
}
