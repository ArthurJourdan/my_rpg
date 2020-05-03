/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** go_start.c
*/

#include "global.h"
#include "gui.h"
#include "a_malloc.h"
#include "xml_parser.h"
#include "my_rpg.h"

void go_start(global_t *global)
{
    change_scene(GS, GAME);
}

void go_restart(global_t *global)
{
    int tmp = GGM;

    pixels_destroy(global);
    player_destroy(global);
    global->game = fill_in_data_game(global->fp_game, global);
    GGM = tmp;
    init_game(global);
    global->game.event.type = -1;
    change_scene(GS, HOME);
}
