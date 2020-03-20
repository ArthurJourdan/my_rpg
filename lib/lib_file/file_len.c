/*
** EPITECH PROJECT, 2020
** my_lib_file
** File description:
** file_len.c
*/

#include "file.h"
#include "my.h"

size_t file_len(char const *filepath)
{
    FILE *fd = fopen(filepath, "r");
    char *buff = NULL;
    size_t zero = 0;
    size_t len = 0;

    if (!fd)
        return 0;
    while (getline(&buff, &zero, fd) != -1) {
        len++;
        free(buff);
        buff = NULL;
    }
    fclose(fd);
    return len;
}
