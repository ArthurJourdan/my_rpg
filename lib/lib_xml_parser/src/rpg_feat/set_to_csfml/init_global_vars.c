/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** init_global_vars.c
*/

#include "my.h"
#include "file.h"
#include "xml_parser.h"

global_t *init_global_vars(char const global_fp[], global_t *global_struct)
{
    char **file = get_entire_file_double_arr(global_fp);

    if (!global_fp || !file)
        return NULL;
    global_struct->window = init_window((const char **)file);
    global_struct->fps = cpy_var_int_double_arr("FPS ", " fps=", file);
    global_struct->volume = cpy_var_int_double_arr("Volume ", " volume=", file);
    global_struct->game.maze_size = \
    cpy_var_int_double_arr("Maze_size ", " size=", file);
    global_struct->cinematic = false;
    free_double_char_arr(file);
    return global_struct;
}
