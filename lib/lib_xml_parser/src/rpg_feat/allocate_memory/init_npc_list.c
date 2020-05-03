/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** init_npc_list.c
*/

#include "my.h"
#include "file.h"

#include "sfml_tools.h"
#include "a_malloc.h"
#include "npc.h"

static npc_t *set_one_to_null(void)
{
    npc_t *npc = a_malloc(sizeof(npc_t) | A_LIST(2));

    if (!npc)
        return NULL;
    npc->id = -1;
    npc->sprite = NULL;
    npc->text = NULL;
    npc->action = NULL;
    npc->actioning = false;
    npc->pos = (sfVector2f){0, 0};
    npc->idx_texture = (sfVector2i){0, 0};
    npc->map_pos = (sfVector2i){0, 0};
    npc->clock = sfClock_create();
    npc->time_action = 0.2f;
    return npc;
}

npc_t **init_npc_list(char **file)
{
    npc_t **npc = NULL;
    size_t nb_npc = count_occurences("NPC ", file);

    if (!nb_npc)
        return NULL;
    npc = a_malloc(sizeof(npc_t *) * (nb_npc + 1) | A_LIST(2));
    for (size_t page = 0; page < nb_npc; page++) {
        npc[page] = set_one_to_null();
        if (!npc[page])
            return npc;
    }
    npc[nb_npc] = NULL;
    return npc;
}
