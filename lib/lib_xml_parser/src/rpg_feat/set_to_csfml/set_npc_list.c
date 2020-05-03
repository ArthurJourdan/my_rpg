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

static actions_npc_t const all_actions[] = {
    {"None", NULL},
    {"Discuss", &npc_discuss},
    {"Zoom", &npc_zoom}
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
    npc->map_pos.x = cpy_var_int(" map_pos_x=", line);
    npc->map_pos.y = cpy_var_int(" map_pos_y=", line);
    npc->text = malloc(sizeof(text_t));
    npc->text = set_any_text(line, npc->text);
    npc->action = choose_action(line);
    npc->pos = get_coordinates(line);
    npc->time_action = cpy_var_float(" time_action=", line);
}

void set_npc_list(char **file, npc_t **npc_list)
{
    size_t nb_npcs = count_occurences("NPC ", file);
    size_t idx = 0;

    for (size_t a = 0; file[a]; a++) {
        if (get_pos_word_in_str("NPC ", file[a]) == -1)
            continue;
        npc_list[idx]->id = idx;
        set_caracteristics(npc_list[idx], file[a]);
        idx++;
    }
}