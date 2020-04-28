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

sfSprite **fill_layers(char **files, sfRenderWindow *window)
{
    size_t b = 0;
    sfSprite **layers = NULL;
    size_t nb_layer = my_arrlen(files);

    if (!nb_layer)
        return NULL;
    layers = malloc(sizeof(sfSprite *) * (nb_layer + 1));
    if (!layers)
        return NULL;
    for (size_t a = 0; a < nb_layer; a++) {
        layers[a] = NULL;
        if (is_file_openable(files[a])) {
            layers[b++] = create_image_fullscreen(NULL, window, files[a]);
        }
    }
    layers[nb_layer] = NULL;
    return layers;
}

char **set_layer_paths(char *dir_path, char * const name)
{
    char **files = NULL;
    char **required = NULL;

    if (!(files = get_filepaths_maps(dir_path, DT_REG)))
        return NULL;
    for (size_t a = 0; files[a]; a++) {
        if (get_pos_word_in_str(name, files[a]) != (-1)) {
            required = add_str_to_arr(required, files[a], true, false);
        }
    }
    free_double_char_arr(files);
    return required;
}

static maps_t *fill_map_layers(maps_t *map, char * const dir_path,
sfRenderWindow *window)
{
    char **files = NULL;

    if ((files = set_layer_paths(dir_path, "l1"))) {
        map->layers1 = fill_layers(files, window);
        free_double_char_arr(files);
    }
    if ((files = set_layer_paths(dir_path, "l2"))) {
        map->layers2 = fill_layers(files, window);
        free_double_char_arr(files);
    }
    if (!map->layers1 && !map->layers2)
        return NULL;
    if ((files = set_layer_paths(dir_path, "colision"))) {
        map->colision = sfImage_createFromFile(files[0]);
        free_double_char_arr(files);
    }
    if (!map->colision)
        return NULL;
    return map;
}

static maps_t *set_one_struct(char * const dir_path, sfRenderWindow *window)
{
    maps_t *map = NULL;

    if (!(map = malloc(sizeof(maps_t)))) {
        return NULL;
    }
    map->layers1 = NULL;
    map->layers2 = NULL;
    map->colision = NULL;
    map = fill_map_layers(map, dir_path, window);
    return map;
}

maps_t **init_maps(char dir_path[], sfRenderWindow *window)
{
    char **each_dir_path = NULL;
    maps_t **maps = init_struct_arr_map(dir_path);

    if (!dir_path || !is_dir_openable(dir_path) || !maps)
        return NULL;
    each_dir_path = get_filepaths(dir_path, DT_DIR);
    sort_arr_alphabetically(each_dir_path);
    for (size_t a = 0; each_dir_path[a]; a++) {
        maps[a] = set_one_struct(each_dir_path[a], window);
        if (!maps[a])
            break;
    }
    free_double_char_arr(each_dir_path);
    return maps;
}