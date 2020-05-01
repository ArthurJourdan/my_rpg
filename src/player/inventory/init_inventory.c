/*
** EPITECH PROJECT, 2020
** init inventory
** File description:
** init the invenotory of player
*/

#include "my_rpg.h"
#include "rpg_structs.h"
#include "player.h"
#include "sfml_tools.h"

void init_player_inventory(player_t *player)
{
    player->p_invent = malloc(sizeof(player_invent_t));
    player->p_invent->nb_spells = 0;
    player->p_invent->spell_nodes = malloc(sizeof(spn_t) * 2);
    player->p_invent->spell_nodes[0].spell_id = -1;
    player->p_invent->spell_nodes[1].spell_id = -1;
    player->p_invent->invent_bg = create_image(NULL, inventory_bg_path);
}
