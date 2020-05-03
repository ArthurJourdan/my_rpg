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

#include <stdbool.h>

struct global_vars;

typedef struct npc {
    int id;
    sfSprite ***sprite;
    sfVector2i idx_texture;
    sfVector2i map_pos;
    sfVector2f pos;
    text_t *text;
    void (*action)(struct global_vars *, size_t);
    bool actioning;
    sfClock *clock;
    float time_action;
} npc_t;

typedef struct actions_npc {
    char * const name_act;
    void (*action)(struct global_vars *, size_t);
} actions_npc_t;

void npc_appear(struct global_vars *global);

void display_npc(struct global_vars *global, size_t npc_idx);

// ACTIONS
void npc_discuss(struct global_vars *global, size_t npc_idx);
void npc_zoom(struct global_vars *global, size_t npc_idx);

// !ACTIONS

#endif /* !NPC_H */
