/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** strlenhuponireticagu
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    if (str)
        while (*(str + i)) {
            i++;
        }
    return (i);
}

int my_arrlen(char ** const arr)
{
    int i = 0;

    while (*(arr + i)) {
        i++;
    }
    return (i);
}

int my_len_tot(char const *str)
{
    static int len = 0;

    len += my_strlen(str);
    return len;
}
