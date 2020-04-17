/*
** EPITECH PROJECT, 2020
** my_lib_file
** File description:
** get_pos_word_in_double_arr.c
*/

#include "file.h"

ssize_t get_pos_word_in_double_arr(char const *word, char const **arr)
{
    if (!word || !arr || !arr[0])
        return -1;
    for (size_t line = 0; arr[line]; line++) {
        if (get_pos_word_in_str(word, arr[line]) != -1)
            return line;
    }
    return -1;
}
