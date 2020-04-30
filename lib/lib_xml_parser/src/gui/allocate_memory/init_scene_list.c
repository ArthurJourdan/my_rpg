/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** init_scene_list.C
*/

#include "my.h"
#include "gui.h"
#include "shorting_defines.h"
#include "xml_parser.h"
#include "file.h"
#include "print.h"

static const char *names[5] = {
    "Starting_menu",
    "Game",
    "Pause",
    "Options",
    "Tutorial"
};

static scene_t *init_one_scene(scene_t *scene)
{
    scene->name = NULL;
    scene->sound = NULL;
    scene->images = NULL;
    scene->music = NULL;
    scene->texts = NULL;
    scene->buttons = NULL;
    scene->to_do = NULL;
    return scene;
}

static bool malloc_scene(gui_t *scene_list, size_t nb_scene)
{
    scene_list->scenes = malloc(sizeof(scene_t *) * (nb_scene + 1));
    if (!scene_list->scenes)
        return false;
    for (size_t a = 0; a < nb_scene; a++) {
        scene_list->scenes[a] = malloc(sizeof(scene_t));
        if (!scene_list->scenes[a])
            return false;
        scene_list->scenes[a] = init_one_scene(scene_list->scenes[a]);
    }
    scene_list->scenes[nb_scene] = NULL;
    return true;
}

static bool place_name(gui_t *sc_list, char *name_sc, int nb_line)
{
    if (!name_sc)
        return false;
    for (size_t c = 0; c < ARRAY_SIZE(names); c++) {
        if (my_str_n_cmp(name_sc, names[c], my_strlen(names[c]))) {
            sc_list->scenes[c]->name = my_strcpy((char *)name_sc);
            free(name_sc);
            return true;
        }
    }
    free(name_sc);
    my_dprintf(2, "%sName of scene not correct at line %i\n", RED, nb_line);
    return false;
}

static bool assign_names(gui_t *scene_list, char const **file)
{
    char *name_scene = NULL;

    for (size_t line = 0; file[line]; line++) {
        if (get_pos_word_in_str("Scene", file[line]) != -1 &&
get_pos_word_in_str("name=", file[line]) != -1) {
            name_scene = cpy_var_name("name=", file[line]);
            if (!place_name(scene_list, name_scene, line)) {
                return false;
            }
        }
    }
    return true;
}

bool init_scene_list(char const **file, gui_t *scene_list)
{
    size_t nb_scene = ARRAY_SIZE(names);

    if (!malloc_scene(scene_list, nb_scene))
        return false;
    if (!assign_names(scene_list, file))
        return false;
    if (!scene_list->scenes)
        return false;
    return true;
}
