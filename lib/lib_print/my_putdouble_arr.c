/*
** EPITECH PROJECT, 2020
** lib
** File description:
** my_putdouble_array.c
*/

#include "my.h"
#include "print.h"

void my_putdouble_arr(int const output, char **arr)
{
    int last_frame = 0;

    for (int a = 0; arr[a] != NULL; a++) {
        last_frame = my_strlen(arr[a]);
        my_putstr(output, arr[a]);
    }
}
