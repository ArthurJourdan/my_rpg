/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** set_ennemy_dict.c
*/

#include "my.h"
#include "file.h"

#include "xml_parser.h"

#include "rpg_structs.h"
#include "global.h"
#include "my_rpg.h"

static void set_caracteristics(e_dict_t *ennemy_page, char * const line)
{
    sfVector2f hitbox_tmp = get_dimensions(line);

    ennemy_page->damage = cpy_var_int(" damage=", line);
    ennemy_page->move_speed = cpy_var_int(" speed=", line);
    ennemy_page->life = cpy_var_int(" life=", line);
    ennemy_page->hitbox = rect(0, 0, (int)hitbox_tmp.x, (int)hitbox_tmp.y);
}

void set_ennemy_dict(char **file, e_dict_t **ennemy_dict)
{
    size_t nb_ennemies = count_occurences("Ennemy ", file);
    size_t pos = 0;

    for (size_t page = 0; page < nb_ennemies; page++) {
        pos += get_pos_word_in_arr("Ennemy ", (char const **)file + pos);
        if (get_pos_word_in_arr("Ennemy ", (char const **)file + pos) == -1)
            break;
        ennemy_dict[page]->id = page;
        set_caracteristics(ennemy_dict[page], file[pos]);
        ennemy_dict[pos]->sprite = set_sprite_arr(file[pos]);
    }
}