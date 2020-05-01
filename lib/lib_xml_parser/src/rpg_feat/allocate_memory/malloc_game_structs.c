/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** malloc_game_structs.c
*/

#include "my.h"

#include "rpg_structs.h"

#include "xml_parser.h"

game_t malloc_all_game_structs(char **file)
{
    game_t game;

    game.spell_dict = init_spell_dict(file);
    game.ennemy_dict  = init_ennemy_dict(file);
    game.npc_list  = init_npc_list(file);
    return game;
}