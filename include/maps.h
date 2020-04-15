/*
** EPITECH PROJECT, 2020
** MUL_rpg
** File description:
** maps.h
*/

#ifndef MAPS_H
#define MAPS_H

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "time.h"
#include <SFML/Audio.h>

#include "gui.h"
#include "shorting_defines.h"

typedef struct maps {
    sfSprite **layers;
    sfSprite *collision;
} maps_t;

char **get_filepaths_maps(char *dirpath, unsigned char type);

maps_t **init_struct_arr_map(char dir_path[]);

maps_t **init_maps(char dir_path[], sfRenderWindow *window);

#endif /* MAPS_H */
