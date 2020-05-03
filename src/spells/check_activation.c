/*
** EPITECH PROJECT, 2020
** check_activation
** File description:
** checks the spell activation
*/

#include "my_rpg.h"

static const s_types_t spells[1] =
{
    {targeted, &targeted_spell}
};

void check_spell_type(int id, global_t *global, int index)
{
    for (int i = 0; i < 1; i++) {
        if (GG.spell_dict[id]->stype == spells[i].type)
            spells[i].spell_fptr(&GG, index);
    }
}

void check_spell_active(global_t *global)
{
    sfFloatRect origin = {0, 0, 0, 0};
    sfVector2f origin_pos = {0, 0};

    if (GGPIS[0].spell_id != -1 && sfKeyboard_isKeyPressed(GGPIS[0].key) &&
    !GGO->s_obj[0].obj_status) {
        GGO->s_obj[0].img = sfSprite_copy(GGS[GGPIS[0].spell_id]->spell_img);
        origin = sfSprite_getGlobalBounds(GGO->s_obj[0].img);
        origin_pos = (sfVector2f){origin.width / 2, origin.height / 2};
        sfSprite_setOrigin(GGO->s_obj[0].img, origin_pos);
        GGO->s_obj[0].speed.x = GGS[GGPIS[0].spell_id]->travel_speed;
        GGO->s_obj[0].speed.y = GGS[GGPIS[0].spell_id]->travel_speed;
        GGO->s_obj[0].collider = &GGS[GGPIS[0].spell_id]->collider;
        GGO->s_obj[0].dir = GGPL;
        GGO->s_obj[0].range = GGS[GGPIS[0].spell_id]->range;
        check_spell_type(GGPIS[0].spell_id, global, 0);
    } else if (GGPIS[1].spell_id != -1 &&
    sfKeyboard_isKeyPressed(GGPIS[1].key  && !GGO->s_obj[1].obj_status)) {
        GGO->s_obj[1].img = sfSprite_copy(GGS[GGPIS[1].spell_id]->spell_img);
        check_spell_type(GGPIS[1].spell_id, global, 1);
    }
}
