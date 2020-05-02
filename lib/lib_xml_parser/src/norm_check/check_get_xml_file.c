/*
** EPITECH PROJECT, 2020
** xml_parser
** File description:
** check_get_xml_file.c
*/

#include "file.h"
#include "xml_parser.h"
#include "print.h"

static char * const MSG = "\n%sFile -> %s -> good\n\n%s";

char **check_get_xml_file(char const *fp)
{
    char **file = NULL;

    if (!fp || !is_file_openable(fp))
        return NULL;
    file = get_entire_file_double_arr(fp);
    if (!file || !file[0])
        return NULL;
    if (!is_it_xml((char const **)file)) {
        return NULL;
    }
    my_dprintf(STDERR_FILENO, MSG, LIGHT_GREEN, fp, DEFAULT);
    return file;
}