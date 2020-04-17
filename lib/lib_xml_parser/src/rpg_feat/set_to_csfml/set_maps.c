/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** set_maps.c
*/

#include "my.h"
#include "maps.h"
#include "file.h"
#include "gui.h"
#include "maps.h"
#include "sfml_tools.h"

void fill_layers(maps_t *map, size_t nb_layer,
char **files, sfRenderWindow *window)
{
    size_t b = 0;

    map->layers = malloc(sizeof(sfSprite *) * nb_layer + 1);
    if (!map->layers)
        return;
    for (size_t a = 0; a + 1 < nb_layer - 1; a++) {
        map->layers[b] = NULL;
        if (is_file_openable(files[a])) {
            map->layers[b++] = create_image_fullscreen(NULL, window, files[a]);
        }
    }
    map->collision = NULL;
    if (is_file_openable(files[nb_layer - 1]))
        map->collision = create_image_fullscreen(NULL,
        window, files[nb_layer - 1]);
    map->layers[nb_layer] = NULL;
}

static maps_t *set_one_struct(char *dir_path, sfRenderWindow *window)
{
    char **files = NULL;
    maps_t *map = NULL;
    size_t nb_layer = nb_in_dir(dir_path, DT_REG);

    if (nb_layer < 2)
        return NULL;
    if (!(files = get_filepaths_maps(dir_path, DT_REG)))
        return map;
    if (!(map = malloc(sizeof(maps_t)))) {
        free_double_char_arr(files);
        return NULL;
    }
    map->layers = NULL;
    map->collision = NULL;
    fill_layers(map, nb_layer, files, window);
    free_double_char_arr(files);
    return map;
}

maps_t **init_maps(char dir_path[], sfRenderWindow *window)
{
    char **each_dir_path = NULL;
    maps_t **maps = init_struct_arr_map(dir_path);

    if (!dir_path || !is_dir_openable(dir_path) || !maps)
        return NULL;
    each_dir_path = get_filepaths(dir_path, DT_DIR);
    if (!each_dir_path)
        return NULL;
    for (size_t a = 0; maps[a] && each_dir_path[a]; a++) {
        maps[a] = set_one_struct(each_dir_path[a], window);
        if (!maps[a])
            break;
    }
    free_double_char_arr(each_dir_path);
    return maps;
}