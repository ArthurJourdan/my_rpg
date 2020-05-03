/*
** EPITECH PROJECT, 2020
** sfml lib
** File description:
** add_texture.c
*/

#include "my.h"
#include "sfml_tools.h"
#include "file.h"

void add_texture_rectshape(sfRectangleShape *rect, char *filepath)
{
    sfTexture *texture = NULL;

    if (!filepath || !is_file_openable(filepath))
        return;
    texture = sfTexture_createFromFile(filepath, NULL);
    if (!texture)
        return;
    sfRectangleShape_setTexture(rect, texture, sfTrue);
}