/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** set_game_object
*/

#include "my.h"
#include "gui.h"
#include "shorting_defines.h"
#include "xml_parser.h"

static int choose_tower(char const *line, gui_t *scene_list, int scene_nb)
{
    int index = 0;
    char *name_object = NULL;

    for (; scene_list->scenes[scene_nb]->towers[index]; index++) {
        if (name_object) {
            name_object = free_char_to_null(name_object);
        }
        name_object = cpy_var_name("name=", line);
        if (my_strcmp(name_object, SL[scene_nb]->towers[index]->name)) {
            free(name_object);
            return index;
        }
    }
    return -1;
}

static int choose_object(char const *line, gui_t *sc_list, int sc_nb, char id)
{
    int index = 0;
    char *name_object = NULL;

    if (id == 't') {
        index = choose_tower(line, sc_list, sc_nb);
        return index;
    } else {
        for (; sc_list->scenes[sc_nb]->enemies[index]; index++) {
            if (name_object) {
                name_object = free_char_to_null(name_object);
            }
            name_object = cpy_var_name("name=", line);
            if (my_strcmp(name_object, SCL_O->ENN[index]->name)) {
                free(name_object);
                return index;
            }
        }
    }
    return -1;
}

void set_game_object(char const *line, gui_t *sc_list, char const *which_sc)
{
    int sc_nb = scene_chooser(sc_list, which_sc);
    char id = get_id(line);
    int obj_index = choose_object(line, sc_list, sc_nb, id);

    if (obj_index != -1) {
        if (id == 't') {
            set_tower(line, sc_list, sc_nb, obj_index);
        } else {
            set_enemy(line, sc_list, sc_nb, obj_index);
        }
    }
}
