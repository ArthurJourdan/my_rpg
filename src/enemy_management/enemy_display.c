/*
** EPITECH PROJECT, 2020
** enemy_display.c
** File description:
** d
*/

#include "my_rpg.h"

static void display_enemy_sprite(global_t *global, e_obj_t *enemy)
{
    sfVector2u size = sfTexture_getSize(sfSprite_getTexture(HEALTHBARSPR));

    size.x = size.x * E_HP / E_MHP;
    sfSprite_setTextureRect(HEALTHBARSPR, rect(0, 0, size.x, size.y));
    sfSprite_setPosition(E_DICT[E_ID]->sprite[E_FACING][E_FRAME], E_POS);
    sfSprite_setPosition(HEALTHBARSPR, vec2f(E_POS.x, E_POS.y - 10));
    sfRenderWindow_drawSprite(GW,
    E_DICT[E_ID]->sprite[E_FACING][E_FRAME], NULL);
    sfRenderWindow_drawSprite(GW, HEALTHBARSPR, NULL);
    return;
}

void display_enemy(global_t *global)
{
    for (int i = 0; i < 64; i++) {
        if (GGOE[i]->obj_status == true) {
            display_enemy_sprite(global, GGOE[i]);
        }
    }
    return;
}
