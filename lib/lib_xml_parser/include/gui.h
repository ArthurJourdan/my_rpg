/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** gui.h"
*/

#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "time.h"
#include <SFML/Audio.h>

#include "my.h"
#include "button.h"
#include "text.h"

struct gui;

typedef struct scene {
    char *name;
    sfSound *sound;
    sfSprite **images;
    sfMusic *music;
    text_t **texts;
    button_t **buttons;
    void (*to_do)(struct gui *);
} scene_t;

typedef struct gui {
    scene_t **scenes;
    unsigned short index;
} gui_t;

enum scene_names {
    HOME = 0,
    GAME = 1,
    PAUSE = 2,
    OPTIONS = 3,
    TUTO = 4
};

#endif /* !GUI_H */
