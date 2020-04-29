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

extern const font_path;
extern const pickup_sen;
extern const replace_sen;
extern const text_size;
extern const pickup;
extern const spell1;
extern const spell2;

int show_pickup(global_t *global)
{
    sfText *pickup = create_text(pickup, pickup_sen, font_path, text_size);

    display_one_text(global->window, pickup);
    if (sfKeyboard_isKeyPressed(pickup)) {
        sfText_destroy(pickup);
        return 1;
    } else {
        sfText_destroy(pickup);
        return 0;
    }
}

int show_replace(global_t *global)
{
    sfText *replace = create_text(replace, replace_sen, font_path, text_size);

    display_one_text(global->window, replace);
    if (sfKeyboard_isKeyPressed(spell1))
        return 1;
    else if (sfKeyboard_isKeyPressed(spell2))
        return 2;
    return 0;
}
