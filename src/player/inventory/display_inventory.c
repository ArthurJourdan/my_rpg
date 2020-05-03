/*
** EPITECH PROJECT, 2020
** display_inventory
** File description:
** display_inventory
*/

#include "my_rpg.h"
#include "player.h"
#include "sfml_tools.h"

void display_inventory(global_t *global)
{
    sfVector2f invent_pos1 = {10, GGH - 100};
    sfVector2f invent_pos2 = {110, GGH - 100};

    sfSprite_setPosition(GGP.p_invent->invent_bg, invent_pos1);
    sfRenderWindow_drawSprite(GW, GGP.p_invent->invent_bg, NULL);
    sfSprite_setPosition(GGP.p_invent->invent_bg, invent_pos2);
    sfRenderWindow_drawSprite(GW, GGP.p_invent->invent_bg, NULL);
    if (GGP.p_invent->spell_nodes[0].spell_id != -1) {
        sfSprite_setPosition(GGS[GGPIS[0].spell_id]->spell_img, invent_pos1);
        sfRenderWindow_drawSprite(GW, GGS[GGPIS[0].spell_id]->spell_img, NULL);
    }
    if (GGP.p_invent->spell_nodes[1].spell_id != -1) {
        sfSprite_setPosition(GGS[GGPIS[1].spell_id]->spell_img, invent_pos2);
        sfRenderWindow_drawSprite(GW, GGS[GGPIS[1].spell_id]->spell_img, NULL);
    }
}
