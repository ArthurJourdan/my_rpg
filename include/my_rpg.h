/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** my_rpg.h
*/

#ifndef MY_RPG_H
#define MY_RPG_H

#include "global.h"
#include "rpg_structs.h"

void rpg_manager(global_t *global);

/*INIT*/
void init_game(game_t *game);
void init_player(player_t *player);
void init_controls(controls_t *controls);

#endif /* !MY_RPG_H */
