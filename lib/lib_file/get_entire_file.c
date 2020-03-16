/*
** EPITECH PROJECT, 2020
** lib_file
** File description:
** get_entire_file.c
*/

#include "file.h"
#include "my.h"
#include "print.h"

char *get_entire_file(char const *filepath)
{
    FILE *fd = fopen(filepath, "r");
    char *buff = NULL;
    size_t zero = 0;
    int ret_get_l = 0;
    char *entire_file = NULL;

    ret_get_l = getline(&buff, &zero, fd);
    while (ret_get_l != -1) {
        entire_file = my_strcat_free(entire_file, buff);
        ret_get_l = getline(&buff, &zero, fd);
    }
    free(buff);
    fclose(fd);
    return entire_file;
}

char **get_entire_file_double_arr(char const *filepath)
{
    FILE *fd = fopen(filepath, "r");
    char *buff = NULL;
    size_t zero = 0;
    int ret_get_l = 0;
    char **entire_file = NULL;
    int len = 0;

    for (; (ret_get_l = getline(&buff, &zero, fd)) != -1; len++);
    free(buff);
    fclose(fd);
    fd = fopen(filepath, "r");
    entire_file = malloc(sizeof(char *) * (len + 1));
    entire_file[0] = NULL;
    ret_get_l = getline(&entire_file[0], &zero, fd);
    for (size_t a = 1; ret_get_l != -1; a++) {
        entire_file[a] = NULL;
        ret_get_l = getline(&entire_file[a], &zero, fd);
    }
    entire_file[len] = NULL;
    fclose(fd);
    return entire_file;
}
