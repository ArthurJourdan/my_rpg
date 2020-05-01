/*
** EPITECH PROJECT, 2020
** display_spell_obj.c
** File description:
** display_spell obj
*/

#include "my_rpg.h"
#include "rpg_structs.h"
#include "sfml_tools.h"

void display_spell_obj_txt(global_t *global, int text)
{
    if (!GGO)
        return;
    if (text == 0)
        return;
    else if (text == 1) {
        sfText_setPosition(GGO->sp_obj_g[0].pickup_text,
        (sfVector2f){400, 500});
        display_one_text(GW, GGO->sp_obj_g[0].pickup_text);
    } else {
        sfText_setPosition(GGO->sp_obj_g[0].replace_text,
        (sfVector2f){400, 500});
        display_one_text(GW, GGO->sp_obj_g[0].replace_text);
    }
}

void display_spell_obj(global_t *global, int index)
{
    sfVector2f spr_pos = {GGO->sp_obj_g[index].CO, GGO->sp_obj_g[index].CT};

    if (GGO->sp_obj_g[index].active) {
        sfSprite_setPosition(GGO->sp_obj_g[index].image, spr_pos);
        sfRenderWindow_drawSprite(GW, GGO->sp_obj_g[index].image, NULL);
    }
}
