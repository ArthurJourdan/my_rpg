/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** init_text_list
*/


#include "my.h"
#include "gui.h"
#include "shorting_defines.h"
#include "xml_parser.h"
#include "file.h"

static sfText **malloc_text(size_t nb_text)
{
    sfText **text = NULL;

    text = malloc(sizeof(sfText *) * (nb_text + 1));
    if (!text)
        return NULL;
    for (size_t a = 0; a < nb_text; a++) {
        text[a] = sfText_create();
    }
    text[nb_text] = NULL;
    return text;
}

static sfText **assign_names(sfText **text, char const **file, char *name_scene)
{
    int nb_text = 0;
    size_t line = get_to_scene(file, name_scene);
    size_t end = get_end_scene(file, name_scene);
    char *info = NULL;

    if (line == (size_t)-1)
        return 0;
    for (; line < end; line++) {
        if (get_pos_word_in_str("Text ", file[line]) != -1) {
            info = cpy_var_name(" name=", file[line]);
            if (info) {
                sfText_setString(text[nb_text], info);
                info = free_char_to_null(info);
            }
            nb_text++;
        }
    }
    return text;
}

static size_t count_texts(char const **file, char *name_scene)
{
    size_t nb_text = 0;
    size_t line = get_to_scene(file, name_scene);
    size_t end = get_end_scene(file, name_scene);

    if (line == (size_t)-1)
        return 0;
    for (; line < end; line++) {
        if (get_pos_word_in_str("Text ", file[line]) != -1) {
            nb_text++;
        }
    }
    return nb_text;
}

sfText **init_text_list(char const **file, char *name_scene)
{
    sfText **text = NULL;
    size_t nb_text = count_texts(file, name_scene);

    if (!nb_text) {
        return NULL;
    }
    text = malloc_text(nb_text);
    if (!text)
        return NULL;
    text = assign_names(text, file, name_scene);
    return text;
}
