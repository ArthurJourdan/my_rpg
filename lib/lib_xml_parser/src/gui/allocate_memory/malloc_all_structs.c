/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** malloc_all_structs.c
*/

#include "my.h"
#include "gui.h"
#include "shorting_defines.h"
#include "xml_parser.h"

gui_t *init_each_scene(char const **file, gui_t *scene_list)
{
    for (size_t a = 0; SL[a]; a++) {
        SL[a]->buttons = init_button_list(file, SL[a]->name);
        SL[a]->texts = init_text_list(file, SL[a]->name);
        SL[a]->images = init_image_list(file, SL[a]->name);
        SL[a]->music = NULL;
        SL[a]->to_do = NULL;
        SL[a]->sound = NULL;
    }
    return scene_list;
}

gui_t *malloc_all_structs(char const **file)
{
    gui_t *scene_list = malloc(sizeof(gui_t));

    if (!scene_list)
        return NULL;
    if (!init_scene_list(file, scene_list))
        return NULL;
    scene_list = init_each_scene(file, scene_list);
    scene_list->index = HOME;
    return scene_list;
}
