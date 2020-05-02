/*
** EPITECH PROJECT, 2020
** placeholder
** File description:
** enemy
*/

#include "a_malloc.h"
#include "my_rpg.h"

e_dict_t *placeholder_load(void)
{
    e_dict_t *e_dict = a_malloc(sizeof(e_dict_t) | A_LIST(1));
    animd_t anim;
    e_dict->id = 0;
    e_dict->damage = 10;
    e_dict->life = 100;
    e_dict->spell_list = NULL;
    e_dict->move_speed = 50;
    e_dict->hitbox = rect(0, 0, 96, 96);
    anim.spritesheet = my_strcpy("assets_rpg/images/spritsheets/monster3.png");
    anim.anim_count = 4;
    anim.anim_frames = a_malloc(sizeof(int) * anim.anim_count);
    anim.anim_frames[0] = 3;
    anim.anim_frames[1] = 3;
    anim.anim_frames[2] = 3;
    anim.anim_frames[3] = 3;
    anim.unit_size.x = 96;
    anim.unit_size.y = 96;
    e_dict->sprite = spritesheet_load(&anim);
    return e_dict;
}
