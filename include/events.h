/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** events.h
*/

#ifndef EVENTS_H
#define EVENTS_H

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "time.h"
#include <SFML/Audio.h>

#include "global.h"

void event_management(global_t *global);

bool stopping_events(global_t *global, sfEvent event);

bool pause_events(global_t *global, sfEvent event);

sfVector2f get_mouse_coo(sfRenderWindow *win);

bool button_management(global_t *global, sfEvent event);


#endif /* !EVENTS_H */
