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
    if (!GGLP.x && !GGLP.y) {
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
}

void display_spell(global_t *global)
{
    if (!GGO)
        return;
    for (int i = 0; i < 2; i++) {
        if (GGO->s_obj[i].obj_status) {
            sfSprite_setPosition(GGO->s_obj[i].img, GGO->s_obj[i].pos);
            sfRenderWindow_drawSprite(GW, GGO->s_obj[i].img, NULL);
        }
    }
}

void display_spell_obj_ground(global_t *global, int index)
{
    sfVector2f spr_pos = {0, 0};

    if (!GGO)
        return;
    spr_pos.x = GGO->sp_obj_g[index].CO;
    spr_pos.y = GGO->sp_obj_g[index].CT;
    if (GGO->sp_obj_g[index].active && !GGLP.x && !GGLP.y) {
        sfSprite_setPosition(GGO->sp_obj_g[index].image, spr_pos);
        sfRenderWindow_drawSprite(GW, GGO->sp_obj_g[index].image, NULL);
    }
}
