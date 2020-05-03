/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** xml_parser.c
*/

#include "my.h"
#include "file.h"
#include "print.h"

#include "xml_parser.h"

#include "gui.h"
#include "global.h"
#include "maps.h"

static char * const FILE_ERR = "%sFile -> %s -> not good\n\n%s";
static char * const MAP_ERR = "%sMap(s) not good\n%s";

static gui_t *fill_in_data_gui(char const *filepath, sfRenderWindow *window)
{
    char **file = NULL;
    gui_t *scene_list = NULL;

    file = check_get_xml_file(filepath);
    if (!file) {
        my_dprintf(2, FILE_ERR, RED, filepath, DEFAULT);
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

static maps_t **init_all_maps(char *filepath, sfRenderWindow *window)
{
    maps_t **maps = init_maps(filepath, window);

    if (!maps) {
        my_dprintf(2, MAP_ERR, RED, DEFAULT);
        return NULL;
    }
    return maps;
}

game_t fill_in_data_game(char * const filepath, global_t *global)
{
    char **file = NULL;
    game_t game = init_game_null();

    file = check_get_xml_file(filepath);
    if (!file) {
        my_dprintf(2, FILE_ERR, RED, filepath, DEFAULT);
        return game;
    }
    game = malloc_all_game_structs(file, game);
    if (!game.spell_dict || !game.ennemy_dict)
        return game;
    set_game_structs(file, game, global);
    free_double_char_arr(file);
    return game;
}

global_t *xml_parser(char const *global_filepath)
{
    global_t *global = NULL;
    filepaths_t *xml_files = NULL;

    if (!(xml_files = get_filepaths_xml(global_filepath)))
        return NULL;
    if (!(global = malloc(sizeof(global_t))))
        return NULL;
    global->game = fill_in_data_game(xml_files->game, global);
    global->fp_game = my_strcpy(xml_files->game);
    if (!(global = init_global_vars(global_filepath, global)))
        return NULL;
    if (!(global->maps = init_all_maps(xml_files->maps , GW)))
        return NULL;
    if (!(global->scene_list = fill_in_data_gui(xml_files->gui, GW)))
        return NULL;
    free_xml_filepaths(xml_files);
    return global;
}
