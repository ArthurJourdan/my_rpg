/*
** EPITECH PROJECT, 2020
** sfml lib
** File description:
** create_image.c
*/

#include "sfml_tools.h"
#include "file.h"

sfSprite *create_image(sfSprite *sprite, char const *filepath)
{
    sfTexture *texture = NULL;

    if (!sprite)
        sprite = sfSprite_create();
    if (!sprite)
        return NULL;
    if (!is_file_openable(filepath))
        return NULL;
    if (!(texture = sfTexture_createFromFile(filepath, NULL)))
        return NULL;
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

sfSprite *create_image_fullscreen(sfSprite *sprite, sfRenderWindow *window,
char const *filepath)
{
    sprite = create_image(sprite, filepath);
    if (!sprite)
        return NULL;
    set_sprite_fullscreen(window, sprite);
    return sprite;
}