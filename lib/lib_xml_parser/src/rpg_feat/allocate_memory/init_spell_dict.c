/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** malloc_spell_dict.c
*/

#include "my.h"
#include "file.h"
#include "a_malloc.h"
#include "my_rpg.h"

static sp_dict_t *set_page_to_null(void)
{
    sp_dict_t *spell_page = malloc(sizeof(sp_dict_t));

    if (!spell_page)
        return NULL;
    spell_page->id = -1;
    spell_page->stype = 0;
    spell_page->category = 0;
    spell_page->base_damage = 0;
    spell_page->activation_radius = 0;
    spell_page->range = NONE_TYPE;
    spell_page->travel_speed = NONE_CAT;
    spell_page->collider = rect(0, 0, 0, 0);
    return spell_page;
}

sp_dict_t **init_spell_dict(char **file)
{
    size_t nb_spells = count_occurences("Spell ", file);
    sp_dict_t **spell_dict = NULL;

    if (!nb_spells)
        return NULL;
    spell_dict = a_malloc(sizeof(sp_dict_t *) * (nb_spells + 1) | A_LIST(2));
    for (size_t page = 0; page < nb_spells; page++) {
        spell_dict[page] = set_page_to_null();
        if (!spell_dict[page])
            return spell_dict;
    }
    spell_dict[nb_spells] = NULL;
    return spell_dict;
}
