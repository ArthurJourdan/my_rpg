/*
** EPITECH PROJECT, 2020
** player_spells
** File description:
** player_spells
*/

#include "my_rpg.h"

void move_spell(global_t *global, int i)
{
    if (GGOS(i).dir == 0) {
        GGOS(i).pos.x -= GGOS(i).speed.x;
        if (GGOS(i).pos.x < GGOS(i).starting_pos.x - GGOS(i).range)
            GGOS(i).obj_status = false;
    }
    if (GGOS(i).dir == 1) {
        GGOS(i).pos.y += GGOS(i).speed.y;
        if (GGOS(i).pos.y > GGOS(i).starting_pos.y + GGOS(i).range)
            GGOS(i).obj_status = false;
    }
    if (GGOS(i).dir == 2) {
        GGOS(i).pos.x += GGOS(i).speed.x;
        if (GGOS(i).pos.x > GGOS(i).starting_pos.x + GGOS(i).range)
            GGOS(i).obj_status = false;
    }
    if (GGOS(i).dir == 3) {
        GGOS(i).pos.y -= GGOS(i).speed.y;
        if (GGOS(i).pos.y < GGOS(i).starting_pos.y - GGOS(i).range)
            GGOS(i).obj_status = false;
    }
}

void check_spell_collision(s_obj_t *spell, global_t *global)
{
    sfBool intersects = sfFalse;
    sfIntRect rect = rect(0, 0, 0, 0);
    sfIntRect srect = rect(0, 0, 0, 0);

    if (!GG.e_obj)
        return;
    for (int i = 0; i < 64; i++) {
        if (GG.e_obj[i]->obj_status) {
            rect = rect(GG.e_obj[i]->pos.x, GG.e_obj[i]->pos.y, 96, 96);
            srect = rect(spell->pos.x, spell->pos.y, 96, 96);
            intersects = rect_collide_check(srect, rect);
            if (intersects == sfTrue) {
                if (GG.e_obj[i]->hp > 0) {
                    GG.e_obj[i]->hp -= GGS[0]->base_damage;
                }
                intersects = sfFalse;
            }
        }
    }

}

void player_spells(global_t *global)
{
    if (!GGS || !GGO)
        return;
    for (int i = 0; i < 2; i++) {
        if (GGO->s_obj[i].obj_status) {
            move_spell(global, i);
            check_spell_collision(&GGO->s_obj[i], global);
        }
    }
}
