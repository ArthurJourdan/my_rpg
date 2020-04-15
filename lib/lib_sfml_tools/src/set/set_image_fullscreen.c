/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** set_image_fullscreen.c
*/

#include "sfml_tools.h"

void set_sprite_fullscreen(sfRenderWindow *window, sfSprite *sprite)
{
    sfVector2u compare = {0};
    sfFloatRect rect = {0};
    sfVector2f scale = {0};

    if (!window || !sprite)
        return;
    compare = sfRenderWindow_getSize(window);
    rect = sfSprite_getGlobalBounds(sprite);
    scale.x = (float)(compare.x / rect.width);
    scale.y = (float)(compare.y / rect.height);
    sfSprite_scale(sprite, scale);
}

void set_sprite_arr_fullscreen(sfRenderWindow *window, sfSprite **sprites)
{
    for (size_t a = 0; sprites[a]; a++)
        set_sprite_fullscreen(window, sprites[a]);
}