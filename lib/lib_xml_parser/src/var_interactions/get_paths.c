/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** get_paths_in_xml.c
*/

#include "xml_parser.h"
#include "my.h"
#include "file.h"

filepaths_t *get_filepaths_xml(const char *global_file_filepath)
{
    filepaths_t *files = malloc(sizeof(filepaths_t));
    char **file = check_get_xml_file(global_file_filepath);

    if (!files || !file)
        return NULL;
    files->gui = cpy_var_name_double_arr("GUI", " path=", file);
    files->maps = cpy_var_name_double_arr("Maps", " path=", file);
    return files;
}