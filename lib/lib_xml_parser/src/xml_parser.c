/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** xml_parser.c
*/

#include "xml_parser.h"
#include "my.h"
#include "gui.h"
#include "print.h"
#include "file.h"
#include "global.h"
#include "maps.h"

gui_t *fill_in_data_gui(char const *filepath, sfRenderWindow *window)
{
    char **file = NULL;
    gui_t *scene_list = NULL;

    file = check_get_xml_file(filepath);
    if (!file) {
        my_dprintf(2, "%sFile : %s not good\n\n%s", RED, filepath, DEFAULT);
        return NULL;
    }
    scene_list = malloc_all_structs((char const **)file);
    if (!scene_list) {
        free_double_char_arr(file);
        return NULL;
    }
    fill_in_gui_struct((char const **)file, scene_list, window);
    free_double_char_arr(file);
    return scene_list;
}

maps_t **init_all_maps(char *filepath, sfRenderWindow *window)
{
    maps_t **maps = init_maps(filepath, window);

    if (!maps) {
        my_dprintf(2, "%sMap(s) not good\n%s", RED, DEFAULT);
        return NULL;
    }
    return maps;
}

global_t *xml_parser(char const *global_filepath)
{
    global_t *global = NULL;
    filepaths_t *xml_files = NULL;

    if (!is_file_openable(global_filepath))
        return NULL;
    if (!(xml_files = get_filepaths_xml(global_filepath)))
        return NULL;
    if (!(global = malloc(sizeof(global_t))))
        return NULL;
    if (!(global = init_global_vars(global_filepath, global)))
        return NULL;
    // if (!(global->maps = init_all_maps(xml_files->maps , GW)))
    //     return NULL;
    if (!(global->scene_list = fill_in_data_gui(xml_files->gui, GW)))
        return NULL;
    return global;
}
