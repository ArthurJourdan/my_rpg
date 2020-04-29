/*
** EPITECH PROJECT, 2020
** sprites load
** File description:
** c
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"
#include "a_malloc.h"

sfSprite *sprite_create(sfTexture *tex, sfIntRect *rect)
{
    sfSprite *spr = sfSprite_create();
    sfSprite_setTexture(spr, tex, sfTrue);
    if (rect != NULL)
        sfSprite_setTextureRect(spr, *rect);
    sfSprite_setOrigin(spr, (sfVector2f){48, 72});
    return spr;
}

sfSprite *sprite_create_from_file(char *path)
{
    sfTexture *tex = sfTexture_createFromFile(path, NULL);
    sfSprite *spr = sprite_create(tex, NULL);
    return spr;
}

sfSprite **sprite_array_load(sfTexture *tex, sfIntRect rect, int amnt, int h)
{
    sfSprite **sprarr = a_malloc(sizeof(sfSprite*) * (amnt + 1) | A_LIST(1));
    sfIntRect rect_c = rect;
    int top = rect.height * h;
    int i = 0;
    for (i = 0; i < amnt; i++) {
        rect_c = rect(rect_c.width * i, top, rect_c.width, rect_c.height);
        sprarr[i] = sprite_create(tex, &rect_c);
    }
    sprarr[i] = NULL;
    return sprarr;
}

sfSprite ***spritesheet_load(animd_t *animd)
{
    sfTexture *tex = sfTexture_createFromFile(SPRSH, NULL);
    sfSprite ***sprarr = a_malloc(sizeof(sfSprite**) * (AC + 1) | A_LIST(1));
    sfIntRect rect = (sfIntRect){0, 0, ASIZE.x, ASIZE.y};
    int i = 0;
    for (i = 0; i < AC; i++) {
        sprarr[i] = sprite_array_load(tex, rect, AF[i], i);
    }
    sprarr[i] = NULL;
    return sprarr;
}
