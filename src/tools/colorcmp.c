/*
** EPITECH PROJECT, 2020
** colorcmp.c
** File description:
** compare colors
*/

#include <SFML/Graphics.h>
#include <stdbool.h>

bool my_colorcmp(sfColor color1, sfColor color2)
{
    if (color1.r == color2.r && color1.g == color2.g &&
        color1.b == color2.b && color1.a == color2.a)
        return true;
    return false;
}
