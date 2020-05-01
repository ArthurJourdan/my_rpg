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
    GGO->sp_obj_g[0].show_text = 1;
    if (sfKeyboard_isKeyPressed(pickup_key)) {
        return 1;
    } else {
        return 0;
    }
}

int show_replace(global_t *global)
{
    GGO->sp_obj_g[0].show_text = 2;
    if (sfKeyboard_isKeyPressed(spell1))
        return 1;
    else if (sfKeyboard_isKeyPressed(spell2))
        return 2;
    return 0;
}
