/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** global.h
*/

#ifndef GLOBAL_H
#define GLOBAL_H

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "time.h"
#include <SFML/Audio.h>
#include "rpg_structs.h"
#include "maps.h"
#include "gui.h"

typedef struct global_vars {
    sfRenderWindow *window;
    size_t fps;
    size_t volume;
    sfEvent event;
    gui_t *scene_list;
    maps_t **maps;
    char *fp_game;
    game_t game;
    bool cinematic;
} global_t;

void destroy_game(global_t *global);

#endif /* !GLOBAL_H */
