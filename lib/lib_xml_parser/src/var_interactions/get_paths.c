/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** get_paths_in_xml.c
*/

#include "xml_parser.h"
#include "my.h"
#include "file.h"
#include "print.h"

static char const * const ERROR_MSG = "Missing path in main xml file for ";

void free_xml_filepaths(filepaths_t *xml_filepaths)
{
    free(xml_filepaths->gui);
    free(xml_filepaths->maps);
    free(xml_filepaths);
}

static filepaths_t *missing_message(char * const fp_missing, char **file)
{
    my_dprintf(2, "%s%s%s\n%s", RED, ERROR_MSG, fp_missing, DEFAULT);
    free_double_char_arr(file);
    return NULL;
}

filepaths_t *get_filepaths_xml(const char *global_file_filepath)
{
    filepaths_t *files = NULL;
    char **file = NULL;

    if (!(file = check_get_xml_file(global_file_filepath))) {
        return NULL;
    }
    files = malloc(sizeof(filepaths_t));
    if (!files)
        return NULL;
    if (!(files->gui = cpy_var_name_double_arr("GUI", " path=", file))) {
        return missing_message("GUI", file);
    }
    if (!(files->maps = cpy_var_name_double_arr("Maps", " path=", file))) {
        return missing_message("Maps", file);
    }
    if (!(files->game = cpy_var_name_double_arr("Game", " path=", file))) {
        return missing_message("Game", file);
    }
    free_double_char_arr(file);
    return files;
}
