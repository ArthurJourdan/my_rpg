/*
** EPITECH PROJECT, 2020
** lib_file
** File description:
** is_file_openable.c
*/

#include "my.h"
#include "file.h"
#include "print.h"

bool is_file_openable(char const *filepath)
{
    int fd = -1;

    if (!filepath || my_str_is_nothing(filepath)) {
        return false;
    }
    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        my_dprintf(2, "%sFile \"%s\" not openable\n%s", RED, filepath, DEFAULT);
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
        my_dprintf(2, "%sFile \"%s\" not openable\n%s", RED, filepath, DEFAULT);
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
        my_dprintf(2, "%sDirectory \"%s\"", RED, filepath);
        my_dprintf(2, " not openable\n%s", DEFAULT);
        return false;
    }
    closedir(fd);
    return true;
}
