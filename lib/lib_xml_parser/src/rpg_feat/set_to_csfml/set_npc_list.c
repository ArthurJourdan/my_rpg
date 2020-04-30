/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** set_npc_list.c
*/

#include "my.h"
#include "file.h"

#include "xml_parser.h"

#include "rpg_structs.h"
#include "npc.h"

static void set_caracteristics(npc_t *npc, char * const line)
{
    npc->sprite = set_sprite_arr(line);
    npc->text = set_any_text(line, NULL);
}

void set_npc_list(char **file, npc_t **npc_dict)
{
    size_t nb_npcs = count_occurences("NPC ", file);
    size_t pos = 0;

    for (size_t a = 0; a < nb_npcs; a++) {
        pos += get_pos_word_in_arr("NPC ", (char const **)file + pos);
        if (get_pos_word_in_arr("NPC ", (char const **)file + pos) == -1)
            break;
        npc_dict[a]->id = a;
        set_caracteristics(npc_dict[a], file[pos]);
    }
}