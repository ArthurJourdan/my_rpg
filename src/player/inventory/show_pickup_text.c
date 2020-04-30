/*
** EPITECH PROJECT, 2020
** show_pickup_text
** File description:
** shows the texts for picking up a spell
*/

#include "my_rpg.h"
#include "rpg_structs.h"
#include "sfml_tools.h"
#include "player.h"

int show_pickup(global_t *global)
{
    sfText *pickup = create_text(NULL, (char * const)pickup_sen,
    (char * const)font_path, text_size);

    display_one_text(global->window, pickup);
    if (sfKeyboard_isKeyPressed(pickup_key)) {
        sfText_destroy(pickup);
        return 1;
    } else {
        sfText_destroy(pickup);
        return 0;
    }
}

int show_replace(global_t *global)
{
    sfText *replace = create_text(NULL, (char * const)replace_sen,
    (char * const)font_path, text_size);

    display_one_text(global->window, replace);
    if (sfKeyboard_isKeyPressed(spell1))
        return 1;
    else if (sfKeyboard_isKeyPressed(spell2))
        return 2;
    return 0;
}
