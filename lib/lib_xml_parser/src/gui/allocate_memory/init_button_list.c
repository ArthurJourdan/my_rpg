/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** init_object_list.c
*/

#include "my.h"
#include "gui.h"
#include "shorting_defines.h"
#include "xml_parser.h"
#include "file.h"
#include "print.h"

static button_t *init_one_button(button_t *button)
{
    button->name = NULL;
    button->rect = NULL;
    button->text = NULL;
    button->nb_animations = 0;
    button->size_tot = 0;
    button->action = NULL;
    button->sound = NULL;
    return button;
}

static button_t **malloc_button(size_t nb_button)
{
    button_t **button = NULL;

    button = malloc(sizeof(button_t *) * (nb_button + 1));
    if (!button)
        return NULL;
    for (size_t a = 0; a < nb_button; a++) {
        button[a] = malloc(sizeof(button_t));
        if (!button[a])
            return NULL;
        button[a] = init_one_button(button[a]);
    }
    button[nb_button] = NULL;
    return button;
}

static button_t **assign_names(button_t **btn, char const **file, char *name_sc)
{
    int nb_button = 0;
    size_t line = get_to_scene(file, name_sc);
    size_t end = get_end_scene(file, name_sc);

    if (line == (size_t)-1)
        return 0;
    for (; line < end; line++) {
        if (get_pos_word_in_str("Button ", file[line]) != -1) {
            btn[nb_button++]->name = cpy_var_name(" name=", file[line]);
        }
    }
    return btn;
}

static size_t count_buttons(char const **file, char *name_scene)
{
    size_t nb_button = 0;
    size_t line = get_to_scene(file, name_scene);
    size_t end = get_end_scene(file, name_scene);

    if (line == (size_t)-1)
        return 0;
    for (; line < end; line++) {
        if (get_pos_word_in_str("Button ", file[line]) != -1)
            nb_button++;
    }
    return nb_button;
}

button_t **init_button_list(char const **file, char *name_scene)
{
    button_t **button = NULL;
    size_t nb_button = count_buttons(file, name_scene);

    if (!nb_button) {
        return NULL;
    }
    button = malloc_button(nb_button);
    if (!button) {
        return NULL;
    }
    button = assign_names(button, file, name_scene);
    return button;
}
