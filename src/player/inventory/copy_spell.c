/*
** EPITECH PROJECT, 2020
** copy_spell
** File description:
** copies a spell
*/

#include "my_rpg.h"
#include "rpg_structs.h"

void copy_spell(int spell_id, sp_dict_t **spells_ref, sp_dict_t *dest)
{
    int spell_pos;

    for (int i = 0; spells_ref[i]; i++)
        if (spells_ref[i]->id == spell_id)
            spell_pos = i;
    dest->id = spells_ref[spell_pos]->id;
    dest->stype = spells_ref[spell_pos]->stype;
    dest->category = spells_ref[spell_pos]->category;
    dest->base_damage = spells_ref[spell_pos]->base_damage;
    dest->mp_cost = spells_ref[spell_pos]->mp_cost;
    dest->cooldown = spells_ref[spell_pos]->cooldown;
    dest->activation_radius = spells_ref[spell_pos]->activation_radius;
    dest->range = spells_ref[spell_pos]->range;
    dest->travel_speed = spells_ref[spell_pos]->travel_speed;
    dest->spell_img = sfSprite_copy(spells_ref[spell_pos]->spell_img);
}
