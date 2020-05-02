/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** npc_discuss.c
*/

#include "global.h"

void npc_discuss(global_t *global, size_t npc_idx)
{
    display_text_struct(GGNPC[npc_idx]->text, GW, FPS, 0);
    }