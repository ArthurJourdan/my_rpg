/*
** EPITECH PROJECT, 2020
** xml_parser
** File description:
** check_get_xml_file.c
*/

#include "file.h"
#include "xml_parser.h"

char **check_get_xml_file(char const *filepath)
{
    char **file = get_entire_file_double_arr(filepath);

    if (!file || !file[0])
        return NULL;
    if (!is_it_xml((char const **)file)) {
        return NULL;
    }
    return file;
}