/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** set_game_structs.c
*/

#include "my.h"

#include "global.h"
#include "rpg_structs.h"
#include "my_rpg.h"

#include "xml_parser.h"

game_t set_game_structs(char **file, game_t game, global_t *global)
{
    set_spell_dict(file, game.spell_dict);
    set_ennemy_dict(file, game.ennemy_dict);
    set_npc_list(file, game.npc_list);
    return game;
}