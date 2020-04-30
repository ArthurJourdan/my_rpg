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
#include "button.h"

static actions_t const all_actions[] = {
    {"None", NULL},
    {"Discuss", NULL/* &npc_discuss */},
    {"Zoom", NULL/* &npc_zoom */}
};

static void *choose_action(char * const line)
{
    char *tmp_act_name = cpy_var_name(" action=", line);

    if (!tmp_act_name)
        return NULL;
    for (size_t a = 0; a < ARRAY_SIZE(all_actions); a++) {
        if (my_strcmp(all_actions[a].name_act, tmp_act_name)) {
            free(tmp_act_name);
            return all_actions[a].action;
        }
    }
    free(tmp_act_name);
    return NULL;
}

static void set_caracteristics(npc_t *npc, char * const line)
{
    npc->sprite = set_sprite_arr(line);
    npc->text = set_any_text(line, NULL);
    npc->action = choose_action(line);
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