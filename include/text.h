/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** text.h
*/

#ifndef TEXT_H
#define TEXT_H

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "time.h"
#include <SFML/Audio.h>
#include <stdbool.h>

typedef struct text {
    char *name;
    char *string;
    sfText *text_sfml;
    bool timed;
    float letter_delay;
    float appear_delay;
} text_t;

#endif /* !TEXT_H */
