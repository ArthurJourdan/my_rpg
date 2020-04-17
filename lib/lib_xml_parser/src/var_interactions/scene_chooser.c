/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** scene_chooser.c
*/

#include "my.h"
#include "gui.h"

size_t scene_chooser(gui_t *scene_list, char const *which_scene)
{
    if (!scene_list->scenes)
        return -1;
    if (!which_scene)
        return -1;
    for (size_t a = 0; scene_list->scenes[a]; a++) {
        if (my_strcmp(scene_list->scenes[a]->name, which_scene))
            return a;
    }
    return -1;
}
