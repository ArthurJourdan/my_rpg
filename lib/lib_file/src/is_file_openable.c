/*
** EPITECH PROJECT, 2020
** lib_file
** File description:
** is_file_openable.c
*/

#include "my.h"
#include "file.h"
#include "print.h"

static char * const ERR_MSG = "%sFile \"%s\" not openable\n%s";

static void open_error_msg(char const *fp, bool file)
{
    if (file) {
        my_dprintf(STDERR_FILENO, "%sFile \"%s\"", YELLOW, fp);
        my_dprintf(STDERR_FILENO, " not openable\n%s", DEFAULT);
    } else {
        my_dprintf(STDERR_FILENO, "%sDirectory \"%s\"", YELLOW, fp);
        my_dprintf(STDERR_FILENO, " not openable\n%s", DEFAULT);
    }
}

bool is_file_openable(char const *filepath)
{
    int fd = -1;

    if (!filepath || my_str_is_nothing(filepath)) {
        return false;
    }
    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        open_error_msg(filepath, true);
        return false;
    }
    close(fd);
    return true;
}

bool is_file_fopenable(char const *filepath)
{
    FILE *fd = NULL;

    if (!filepath || my_str_is_nothing(filepath)) {
        return false;
    }
    fd = fopen(filepath, "r");
    if (!fd) {
        open_error_msg(filepath, true);
        return false;
    }
    fclose(fd);
    return true;
}

bool is_dir_openable(char const *filepath)
{
    DIR *fd = NULL;

    if (!filepath || my_str_is_nothing(filepath)) {
        return false;
    }
    fd = opendir(filepath);
    if (!fd) {
        open_error_msg(filepath, false);
        return false;
    }
    closedir(fd);
    return true;
}
