/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** npc.h
*/

#ifndef NPC_H
#define NPC_H

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#include "text.h"

typedef struct npc {
    int id;
    sfSprite ***sprite;
    sfVector2i map_pos;
    text_t *text;
} npc_t;

#endif /* !NPC_H */
