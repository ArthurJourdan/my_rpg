/*
** EPITECH PROJECT, 2020
** lib_my
** File description:
** free_double_arr.c
*/

#include "my.h"

void free_double_char_arr(char **arr)
{
    size_t a = 0;

    for (; arr[a]; a++) {
        free(arr[a]);
    }
    free(arr);
}
