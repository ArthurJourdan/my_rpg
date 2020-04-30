/*
** EPITECH PROJECT, 2020
** xml_parser_lib
** File description:
** set_color_button.c
*/

#include "my.h"

#include "xml_parser.h"
#include "sfml_tools.h"

static void set_states(button_t *button, char *const line)
{
    char *color_str = NULL;
    sfColor color = sfWhite;

    if ((color_str = cpy_var_name(" idle_color=", line))) {
        color = get_color_from_str(color_str);
        color_str = free_char_to_null(color_str);
        sfRectangleShape_setOutlineColor(button->rect, color);
        button->idle_color = color;
    }
    if ((color_str = cpy_var_name(" hover_color=", line))) {
        color = get_color_from_str(color_str);
        color_str = free_char_to_null(color_str);
        button->hover_color = color;
    }
    if ((color_str = cpy_var_name(" clicked_color=", line))) {
        color = get_color_from_str(color_str);
        color_str = free_char_to_null(color_str);
        button->clicked_color = color;
    }
}

void set_color_button(button_t *button, char * const line)
{
    button->idle_color = sfWhite;
    button->hover_color = sfBlack;
    button->clicked_color = sfTransparent;
    set_states(button, line);
}