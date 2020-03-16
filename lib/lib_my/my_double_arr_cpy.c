/*
** EPITECH PROJECT, 2020
** lib
** File description:
** my_double_arr_cpy.c
*/

#include "my.h"

static char **init_each_arr(char **double_arr, char **cpy, int len_d_arr)
{
    int len_arr = 0;

    for (int a = 0; a < len_d_arr; a++) {
        len_arr = my_strlen(*(double_arr + a));
        *(cpy + a) = malloc(sizeof(char) * len_arr + 1);
        if (!*(cpy + a))
            return NULL;
        for (int b = 0; b < len_arr; b++) {
            *(*(cpy + a) + b) = *(*(double_arr + a) + b);
        }
        *(*(cpy + a) + len_arr) = '\0';
    }
    return cpy;
}

char **my_double_arr_cpy(char **double_arr)
{
    int len_d_arr = my_arrlen(double_arr);
    char **cpy = NULL;

    if (!len_d_arr)
        return NULL;
    cpy = malloc(sizeof(char *) * (len_d_arr + 100));
    if (!cpy)
        return NULL;
    cpy = init_each_arr(double_arr, cpy, len_d_arr);
    if (!cpy)
        return NULL;
    *(cpy + len_d_arr) = NULL;
    return cpy;
}
