/*
** EPITECH PROJECT, 2020
** my_lib_file
** File description:
** are_quotes_filled.c
*/

#include "my.h"

bool are_all_quotes_filled(char const * const line)
{
    size_t check_double = 0;
    size_t check_simple = 0;
    size_t check_magic = 0;

    for (int c = 0; line[c]; c++) {
        if (line[c] == '\"')
            check_double++;
        if (line[c] == '\'')
            check_simple++;
        if (line[c] == '`')
            check_magic++;
    }
    if (check_double % 2 == 1)
        return false;
    if (check_simple % 2 == 1)
        return false;
    if (check_magic % 2 == 1)
        return false;
    return true;
}