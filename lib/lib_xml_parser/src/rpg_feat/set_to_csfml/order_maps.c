/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** oreder_maps.c
*/

#include "my.h"
#include "file.h"
#include "print.h"

static char * const COL_NAME = "colision";

static char * const MSG_COL = "Missing colision map in directory :";
static char * const MSG_MAP = "Missing map in directory :";
static char * const MSG_NONE = "None of the maps are openable in :";
static char * const MSG_COL_NO = "Colision map not openable in :";

static bool disp_error_msg(char * const dirpath, int num_err)
{
    if (num_err == 0)
        my_dprintf(STDERR_FILENO, "%s%s %s\n", RED, MSG_COL, dirpath);
    if (num_err == 1)
        my_dprintf(STDERR_FILENO, "%s%s %s\n", RED, MSG_MAP, dirpath);
    if (num_err == 2)
        my_dprintf(STDERR_FILENO, "%s%s %s\n", RED, MSG_NONE, dirpath);
    if (num_err == 3)
        my_dprintf(STDERR_FILENO, "%s%s %s\n", RED, MSG_COL_NO, dirpath);
    return false;
}

static bool error_handling_maps(char * const dirpath, char **filepaths)
{
    size_t len = my_arrlen(filepaths);
    ssize_t pos = -1;
    bool return_value = false;

    pos = get_pos_word_in_arr(COL_NAME, (char const **)filepaths);
    if (pos == -1) {
        return disp_error_msg(dirpath, 0);
    }
    if (len < 2)
        return disp_error_msg(dirpath, 1);
    for (size_t a = 0; a < len; a++) {
        if (is_file_openable(filepaths[a]))
            return_value = true;
    }
    if (!return_value)
        return disp_error_msg(dirpath, 2);
    if (!is_file_openable(filepaths[pos]))
        return disp_error_msg(dirpath, 3);
    return true;
}

static char **place_colision_at_end(char * const dirpath, char **filepaths)
{
    ssize_t pos = get_pos_word_in_arr(COL_NAME, (char const **)filepaths);
    char *tmp = my_strcpy(filepaths[pos]);
    char **ordered_fp = NULL;

    filepaths = remove_str_to_arr(filepaths, pos, true);
    filepaths = add_str_to_arr(filepaths, tmp, true, true);
}

char **get_filepaths_maps(char * const dirpath, unsigned char type)
{
    char **filepaths = get_filepaths(dirpath, type);

    if (!filepaths)
        return NULL;
    if (!error_handling_maps(dirpath, filepaths)) {
        free_double_char_arr(filepaths);
        return NULL;
    }
    sort_arr_alphabetically(filepaths);
    filepaths = place_colision_at_end(dirpath, filepaths);
    return filepaths;
}