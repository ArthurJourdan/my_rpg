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
void init_layers(layers_t *layers);
void put_sprite(player_t *player, char *filepath);
void init_controls(controls_t *controls);

/*DISP*/
void display_player(sfRenderWindow *win, player_t player, layers_t layers);

/*GAME*/
void player_movements(player_t *player, layers_t *layers);
void my_putmap(layers_t *layers, char *layer1, char *layer2, char *coll);

#endif /* !MY_RPG_H */
