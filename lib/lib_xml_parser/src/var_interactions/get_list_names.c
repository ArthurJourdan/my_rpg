/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** get_list_names.c
*/

#include "my.h"
#include "gui.h"

char **list_button_names(button_t **buttons)
{
    size_t nb_buttons = 0;
    char **list_names = NULL;

    while (buttons[nb_buttons]) {
        nb_buttons++;
    }
    if (!(list_names = malloc(sizeof(char *) * (nb_buttons + 1))))
        return NULL;
    list_names[nb_buttons] = NULL;
    for (size_t a = 0; a < nb_buttons; a++) {
        list_names[a] = my_strcpy(buttons[a]->name);
        if (!list_names[a])
            return NULL;
    }
    return list_names;
}