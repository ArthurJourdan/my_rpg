/*
** EPITECH PROJECT, 2020
** player.h
** File description:
** player.h
*/

#ifndef PLAYER_H_
#define PLAYER_H_

#include "my_rpg.h"
#include "rpg_structs.h"

static const char inventory_bg_path[45] =
"/assets_rpg/images/player/inventory_cell.png";
static const char font_path[52] =
"/assets_rpg/GUI/assets/font/Beathy Demo Version.ttf";
static const char pickup_sen[15] = "Pick up with F";
static const char replace_sen[24] = "Choose spell to replace";
static const int text_size = 10;
static const sfKeyCode spell1 = sfKeyA;
static const sfKeyCode spell2 = sfKeyE;
static const sfKeyCode pickup = sfKeyF;


int show_pickup(global_t *global);
int show_replace(global_t *global);
#endif /* !PLAYER_H_ */
