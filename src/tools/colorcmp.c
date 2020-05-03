/*
** EPITECH PROJECT, 2020
** colorcmp.c
** File description:
** compare colors
*/

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "my_rpg.h"
#include "sfml_tools.h"

sfColor get_pixel_color(sfVector2f next, global_t *global)
{
    sfVector2f scale;
    sfVector2f size;
    sfColor color;

    scale = sfV2F{(float)1650 / (float)GGW, (float)990 / (float)GGH};
    size = sfV2F{next.x * scale.x, next.y * scale.y};
    color = sfImage_getPixel(GGLMM[GGLP.y][GGLP.x].coll, size.x, size.y);
    return color;
}

bool my_colorcmp(sfColor color1, sfColor color2)
{
    if (color1.r == color2.r && color1.g == color2.g &&
        color1.b == color2.b && color1.a == color2.a)
        return true;
    return false;
}
