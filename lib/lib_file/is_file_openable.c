/*
** EPITECH PROJECT, 2020
** lib_file
** File description:
** is_file_openable.c
*/

#include "file.h"

bool is_file_openable(char const *filepath)
{
    int fd = 0;

    if (open(filepath, O_RDONLY) == -1) {
        return false;
    }
    close(fd);
    return true;
}
