/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** display.h
*/

#ifndef DISPLAY_H
#define DISPLAY_H

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#include "text.h"

void display_texts_struct(text_t **texts, sfRenderWindow *window, size_t fps);


#endif /* !DISPLAY_H */
