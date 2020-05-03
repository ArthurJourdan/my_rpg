/*
** EPITECH PROJECT, 2020
** sfml lib
** File description:
** create_text.c
*/

#include "sfml_tools.h"
#include "file.h"

sfText *create_text(sfText *text, char * const str, char * const path_font,
int size)
{
    sfFont *font = NULL;

    if (!text)
        text = sfText_create();
    if (!text)
        return NULL;
    if (str)
        sfText_setString(text, str);
    if (path_font && is_file_openable(path_font)) {
        font = sfFont_createFromFile(path_font);
        sfText_setFont(text, font);
    }
    if (size >= 0) {
        sfText_setCharacterSize(text, size);
    }
    return text;
}
