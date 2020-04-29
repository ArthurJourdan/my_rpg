/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** xml_norm.c
*/

#include "my.h"
#include "print.h"
#include "xml_parser.h"

bool xml_error_msg(char c, int line, int pos)
{
    line++;
    pos++;
    if (c == '=') {
        my_dprintf(2, "%sWrong text arround '%c'", RED, c);
        my_dprintf(2, " at line %i, pos %i\n\n%s", line, pos, DEFAULT);
    }
    if (c == ' ') {
        my_dprintf(2, "%sMissing indicative ", RED);
        my_dprintf(2, "character at line %i\n\n%s", line, DEFAULT);
    }
    if (c == 'a') {
        my_dprintf(2, "%sQuote not filled at ", RED);
        my_dprintf(2, "line %i, pos %i\n\n%s", line, pos);
    }
    if (c == '"' || c == '>' || c == '<') {
        my_dprintf(2, "%sMissplaced '%c' at ", RED, c);
        my_dprintf(2, "line %i, pos %i\n\n%s", line, pos, DEFAULT);
    }
    return false;
}

static bool full_check(char const **file, bool (*ptr)(char const *, int, int))
{
    int check = 0;

    for (int line = 0; file[line]; line++) {
        if (file[line][0] != '#') {
            if (!ptr(file[line], check, line)) {
                return false;
            }
            check = 0;
        }
    }
    return true;
}

bool is_it_xml(char const **file)
{
    if (!file)
        return false;
    bool (*norm[4])(char const *, int, int) = {
        &are_wards_good,
        &are_quotes_filled,
        &are_equals_filled,
        &is_statement_quotation
    };

    for (size_t a = 0; a < ARRAY_SIZE(norm); a++) {
        if (!full_check(file, norm[a])) {
            return false;
        }
    }
    return true;
}
