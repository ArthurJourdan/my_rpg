/*
** EPITECH PROJECT, 2020
** lib/my
** File description:
** my_strcat_path.c
*/

#include "my.h"

char *my_strcat_path(char const *str1, char const *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    int len3 = len1 + len2;
    char *str3 = malloc(sizeof(char) * (len3 + 2));

    for (int a = 0; a < len1; a++)
        *(str3 + a) = *(str1 + a);
    if (*(str1 + len1 - 1) == '/');
    else {
        *(str3 + len1) = '/';
        len1 += 1;
    }
    for (int b = 0; b < len2; b++)
        *(str3 + b + len1) = *(str2 + b);
    *(str3 + (len1 + len2)) = '\0';
    return str3;
}
