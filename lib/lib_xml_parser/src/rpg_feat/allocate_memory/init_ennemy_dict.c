/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** init_ennemy_dict.c
*/

#include "my.h"
#include "file.h"

#include "rpg_structs.h"
#include "a_malloc.h"

static e_dict_t *set_page_to_null(void)
{
    e_dict_t *spell_page = a_malloc(sizeof(e_dict_t) | A_LIST(2));

    if (!spell_page)
        return NULL;
    spell_page->id = -1;
    spell_page->damage = 0;
    spell_page->move_speed = 0;
    spell_page->life = 0;
    spell_page->sprite = NULL;
    return spell_page;
}

e_dict_t **init_ennemy_dict(char **file)
{
    size_t nb_ennemies = count_occurences("Ennemy ", file);
    e_dict_t **ennemy_dict = NULL;

    if (!nb_ennemies)
        return NULL;
    ennemy_dict = a_malloc(sizeof(e_dict_t *) * (nb_ennemies + 1) | A_LIST(2));
    for (size_t page = 0; page < nb_ennemies; page++) {
        ennemy_dict[page] = set_page_to_null();
        if (!ennemy_dict[page])
            return ennemy_dict;
    }
    ennemy_dict[nb_ennemies] = NULL;
    return ennemy_dict;
}
