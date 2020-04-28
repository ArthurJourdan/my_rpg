/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** display_maps.c
*/

#include "maps.h"
#include "sfml_tools.h"

void display_one_map(sfRenderWindow *window, maps_t *map)
{
    if (window && map) {
        display_images(window, map->layers1);
        display_images(window, map->layers2);
    }
}