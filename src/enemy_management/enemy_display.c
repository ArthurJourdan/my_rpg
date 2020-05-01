/*
** EPITECH PROJECT, 2020
** enemy_display.c
** File description:
** d
*/

#include "my_rpg.h"

static void display_enemy_sprite(global_t *global, e_obj_t *enemy)
{
    sfVector2u size = sfTexture_getSize(sfSprite_getTexture(/*healthbarsprite*/));
    size.x = size.x * E_HP / E_MHP;
    sfSprite_setTextureRect(E_DICT[E_ID]->sprite, rect(0, 0, size.x, size.y));
    sfSprite_setPosition(E_DICT[E_ID]->sprite, E_POS);
    sfSprite_setPosition(/*healthbarsprite*/, vec2f(E_POS.x, E_POS.y - 10));
    sfRenderWindow_drawSprite(GW, E_DICT[E_ID]->sprite, NULL);
    sfRenderWindow_drawSprite(GW, /*healthbarsprite*/, NULL);
    return;
}

void display_enemy(global_t *global, e_obj_t *enemy)
{
    for (int i = 0; i < 64; i++) {
        if (GGOE[i]->obj_status)
            display_enemy_sprite(global, GGOE[i]);
    }
    return;
}
