/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** my_stcpy.c
*/

#include "my.h"

char *my_strcpy(char *str)
{
    int len = my_strlen(str);
    char *cpy = NULL;

    if (!len)
        return NULL;
    cpy = malloc(sizeof(char) * (len + 1));
    if (!cpy)
        return NULL;
    for (int a = 0; a < len; a++)
        cpy[a] = str[a];
    cpy[len] = '\0';
    return cpy;
}

char *my_str_n_cpy(char *str, int size)
{
    int len = my_strlen(str);
    char *cpy = NULL;

    if (!len)
        return NULL;
    cpy = malloc(sizeof(char) * (size + 1));
    if (!cpy)
        return NULL;
    for (int a = 0; a < size; a++) {
        if (a >= len)
            cpy[a] = '\0';
        else
            cpy[a] = str[a];
    }
    cpy[size] = '\0';
    return cpy;
}

char *my_str_cpy_until_char(char *str, char c)
{
    int len = 0;
    char *cpy = NULL;

    if (!len)
        return NULL;
    while (str[len] && str[++len] != c);
    cpy = malloc(sizeof(char) * (len + 1));
    if (!cpy)
        return NULL;
    for (int a = 0; a < len; a++) {
        cpy[a] = str[a];
    }
    cpy[len] = '\0';
    return cpy;
}

char *my_str_cpy_quotation(char *str)
{
    char *cpy = NULL;
    size_t pos = 0;
    size_t len = 0;
    size_t str_len = my_strlen(str);

    if (!str_len)
        return NULL;
    while (str[++pos] != '"' && pos < str_len);
    while (str[++pos] != '"' && pos < str_len)
        len++;
    if (pos == str_len)
        return NULL;
    pos -= len;
    cpy = malloc(sizeof(char) * (len + 1));
    if (!cpy)
        return NULL;
    for (int a = 0; a < len; a++) {
        cpy[a] = str[pos + a];
    }
    cpy[len] = '\0';
    return cpy;
}
