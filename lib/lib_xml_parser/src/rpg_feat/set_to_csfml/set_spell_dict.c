/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** set_spell_dict.c
*/

#include "my.h"
#include "file.h"

#include "xml_parser.h"

#include "rpg_structs.h"
#include "global.h"

static str_nb_t types[3] = {
    {"targeted", targeted},
    {"range", range},
    {"status", status}
};

static str_nb_t categories[3] = {
    {"blast", blast},
    {"instant", instant},
    {"sequence", sequence},
};

static void set_caracteristics(sp_dict_t *spell_page, char * const line)
{
    spell_page->base_damage = cpy_var_int(" base_damage=", line);
    spell_page->mp_cost = cpy_var_int(" mp_cost=", line);
    spell_page->cooldown = cpy_var_int(" cooldown=", line);
    spell_page->activation_radius = cpy_var_int(" activation_radius=", line);
    spell_page->range = cpy_var_float(" range=", line);
    spell_page->travel_speed = cpy_var_float(" travel_speed=", line);
}

static void set_type_category(sp_dict_t *spell_page, char * const line)
{
    char *info = NULL;

    info = cpy_var_name(" type=", line);
    if (info) {
        for (size_t type_nb = 0; type_nb < ARRAY_SIZE(types); type_nb++) {
            if (my_strcmp(info, types[type_nb].str))
                spell_page->stype = types[type_nb].nb;
        }
    }
    info = free_char_to_null(info);
    info = cpy_var_name(" category=", line);
    for (size_t cat_nb = 0; cat_nb < ARRAY_SIZE(categories); cat_nb++) {
        if (my_strcmp(info, categories[cat_nb].str))
            spell_page->category = categories[cat_nb].nb;
    }
    info = free_char_to_null(info);
}

void set_spell_dict(char **file, sp_dict_t **spell_dict)
{
    size_t nb_spells = count_occurences("Spell ", file);
    size_t pos = 0;

    for (size_t page = 0; page < nb_spells; page++) {
        pos += get_pos_word_in_arr("Spell ", (char const **)file + pos);
        if (get_pos_word_in_arr("Spell ", (char const **)file + pos) == -1)
            break;
        spell_dict[page]->id = page;
        set_type_category(spell_dict[page], file[pos]);
        set_caracteristics(spell_dict[page], file[pos]);
    }
}