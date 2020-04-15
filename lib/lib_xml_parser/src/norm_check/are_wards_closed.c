/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** are_wards_closed.c
*/

#include "my.h"
#include "print.h"
#include "xml_parser.h"

static char *type[] = {
    "Scene",
    "Game_Object",
    "Button",
    "Music"
};

static size_t check_one_or_more_line(char const *line)
{
    size_t nb_line = 0;

    for (size_t a = 0; line[a] != '\n'; a++)
        for (size_t b = 0; b <= ARRAY_SIZE(type); b++) {
            if (b == ARRAY_SIZE(type)) {
                my_dprintf(2, "%sMissing type at line %i\n", RED, nb_line);
                return false;
            }
            if (my_str_n_cmp(type[b], line, my_strlen(type[b])))
                while (0);
        }
    return nb_line;
}

bool are_wards_closed(char const **file)
{
    USELESS int old_line = 0;

    for (size_t line = 0; file[line]; line++) {
        old_line = line;
        line = check_one_or_more_line(file[line]);
        if (line == (size_t)- 2) {
            return false;
        }
    }
    return true;
}
