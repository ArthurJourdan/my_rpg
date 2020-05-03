/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2020
** File description:
** xml_check_norm_line_by_line.c
*/

#include "my.h"
#include "xml_parser.h"
#include "print.h"
#include "file.h"

static char *checks[7] = {
    "name=",
    "image=",
    "name=",
    "x=",
    "y=",
    "volume=",
    "audio="
};

bool are_equals_filled(char const *line, USELESS int check, int nb_line)
{
    for (size_t b = 0; line[b]; b++) {
        if (line[b] == '=') {
            if (!line[b + 1] || line[b + 1] != '"')
                return xml_error_msg('=', nb_line, b);
            b--;
            if (!line[b] || !my_char_is_alpha_num(line[b], true, true, true))
                return xml_error_msg('=', nb_line, ++b);
            b++;
        }
    }
    return true;
}

bool are_quotes_filled(char const *line, int check, int nb_line)
{
    size_t avoid = 0;

    for (size_t b = 0; line[b] && line[b]; b++) {
        if (b == avoid)
            b++;
        if (line[b] == '"') {
            for (int c = b + 1; line[c]; c++) {
                if (line[c] == '"') {
                    check++;
                    avoid = c;
                    break;
                }
            }
            if (check != 1)
                return xml_error_msg('"', nb_line, b);
            check = 0;
            if (!my_quotation_is_nothing(line + b))
                return xml_error_msg('a', nb_line, b);
        }
    }
    return true;
}

bool are_wards_good(char const *line, int check, int nb_line)
{
    for (size_t b = 0; line[b]; b++) {
        if (line[b] == '<') {
            if (check == 2) {
                check = 1;
            } else if (check) {
                return xml_error_msg(line[b], nb_line, b);
            } else
                check++;
        }
        if (line[b] == '>') {
            if (check != 1) {
                return xml_error_msg(line[b], nb_line, b );
            } else
                check++;
        }
    }
    if (check != 2)
        return xml_error_msg(' ', nb_line, -1);
    return true;
}

bool is_statement_quotation(char const *line, int check, int nb_line)
{
    int pos = 0;

    for (size_t a = 0; a < ARRAY_SIZE(checks); a++) {
        pos = get_pos_word_end_in_str(line, checks[a]);
        if (pos != -1)
            if (line[pos++] != '"') {
                my_dprintf(2, "%swrong position for \"%s\" ", RED, checks[a]);
                my_dprintf(2, "statement at line %i, pos %i\n\n", nb_line, pos);
                check++;
            }
    }
    if (check > 0)
        return false;
    return true;
}
