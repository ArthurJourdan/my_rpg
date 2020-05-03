/*
** EPITECH PROJECT, 2020
** enemy collision
** File description:
** c
*/

#include "my_rpg.h"

sfVector2f get_knockback(sfVector2f ppos, sfVector2f epos)
{
    sfVector2f v = vec2f(ppos.x - epos.x, ppos.y - epos.y);
    float derivative;
    derivative = sqrtf(powf(v.x, 2) + powf(v.y, 2));
    v.x = v.x / derivative * 50;
    v.y = v.y / derivative * 50;
    return v;
}

int pos_in_rect_check(sfVector2f vect, sfIntRect rect)
{
    if (vect.x > rect.left && vect.x < rect.left + rect.width &&
        vect.y > rect.top && vect.y < rect.top + rect.height)
        return 1;
    return 0;
}

int rect_collide_check(sfIntRect rect1, sfIntRect rect2)
{
    if (pos_in_rect_check(rect_topleft(rect1), rect2))
        return 1;
    if (pos_in_rect_check(rect_topright(rect1), rect2))
        return 1;
    if (pos_in_rect_check(rect_botleft(rect1), rect2))
        return 1;
    if (pos_in_rect_check(rect_botright(rect1), rect2))
        return 1;
    if (pos_in_rect_check(rect_topleft(rect2), rect1))
        return 1;
    if (pos_in_rect_check(rect_topright(rect2), rect1))
        return 1;
    if (pos_in_rect_check(rect_botleft(rect2), rect1))
        return 1;
    if (pos_in_rect_check(rect_botright(rect2), rect1))
        return 1;
    return 0;
}

void check_enemy_collision(global_t *global, e_obj_t *enemy)
{
    sfIntRect e_rect = rect(E_POS.x + E_BOX.left, E_POS.y + E_BOX.top,
    E_BOX.width, E_BOX.height);
    sfIntRect p_rect = rect(GGP.pos.x * 2, GGP.pos.y * 2, 96, 96);
    sfVector2f kb;
    if (!rect_collide_check(e_rect, p_rect))
        return;
    GGP.hp -= E_DMG;
    if (GGP.hp <= 0)
        GGP.hp = 0;
    kb = get_knockback(GGP.pos, E_POS);
    GGP.pos = vec2f(GGP.pos.x + kb.x, GGP.pos.y + kb.y);
    return;
}
