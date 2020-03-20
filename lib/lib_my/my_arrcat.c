/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** my_arrcat.c
*/

#include "my.h"

char **my_arrcat(char **arr1, char **arr2, bool free)
{
    size_t len1 = my_arrlen(arr1);
    size_t len2 = my_arrlen(arr2);
    size_t len3 = len1 + len2;
    char **arr3 = malloc(sizeof(char *) * (len3 + 1));

    if (!arr3)
        len3 = 0;
    for (size_t a = 0; a < len3; a++) {
        if (a < len1) {
            arr3[a] = my_strcpy(arr1[a]);
        } else {
            arr3[a] = my_strcpy(arr2[a - len1]);
        }
    }
    arr3[len3] = NULL;
    if (free) {
        free_double_char_arr(arr1);
        free_double_char_arr(arr2);
    }
    return arr3;
}

char ***my_triple_arrcat(char ***arr1, char ***arr2)
{
    size_t len1 = my_triplearrlen(arr1);
    size_t len2 = my_triplearrlen(arr2);
    size_t len3 = len1 + len2;
    char ***arr3 = malloc(sizeof(char **) * (len3 + 1));

    if (!arr3)
        len3 = 0;
    for (size_t a = 0; a < len3; a++) {
        if (a < len1) {
            arr3[a] = double_char_arrcpy(arr1[a], false);
        } else {
            arr3[a] = double_char_arrcpy(arr2[a - len1], false);
        }
    }
    arr3[len3] = NULL;
    return arr3;
}
