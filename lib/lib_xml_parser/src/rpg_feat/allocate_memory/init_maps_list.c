/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** init_maps_list.c
*/

#include "xml_parser.h"
#include "file.h"
#include "maps.h"
#include "a_malloc.h"

maps_t **init_struct_arr_map(char dir_path[])
{
    size_t nb_dirs = nb_in_dir(dir_path, DT_DIR);
    maps_t **maps = NULL;

    if (!dir_path || !is_dir_openable(dir_path) || !nb_dirs)
        return NULL;
    maps = a_malloc(sizeof(maps_t *) * (nb_dirs + 1) | A_LIST(2));
    if (!maps)
        return NULL;
    maps[nb_dirs] = NULL;
    return maps;
}
