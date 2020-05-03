/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** npc_discuss.c
*/

#include "global.h"

void npc_discuss(global_t *global, size_t npc_idx)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        GGNPC[npc_idx]->actioning = false;
    } else {
        display_text_struct(GGNPC[npc_idx]->text, GW, FPS, 0);
    }
}