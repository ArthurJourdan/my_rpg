/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** set_enemy.c
*/

#include "my.h"
#include "gui.h"
#include "shorting_defines.h"
#include "xml_parser.h"

static void load_text(char *info, gui_t *sc_li, int sc_nb, int obj_i)
{
    sfTexture *texture = NULL;
    sfVector2f pos = {300, 1};

    texture = sfTexture_createFromFile(info, NULL);
    info = free_char_to_null(info);
    sfSprite_setTexture(SCL_E[obj_i]->sprite, texture,
    sfFalse);
    sfSprite_setOrigin(SCL_E[obj_i]->sprite, (sfVector2f){22.5, 105});
    sfSprite_setPosition(SCL_E[obj_i]->sprite, pos);
}

static void init_intrect(sfIntRect *rect)
{
    rect->width = 0;
    rect->height = 0;
}

static void load_explosion(char *info, gui_t *game, int sc_nb, int obj_i)
{
    sfTexture *texture = NULL;
    sfVector2f pos = {-1000, -1000};

    if (info) {
        texture = sfTexture_createFromFile(info, NULL);
        info = free_char_to_null(info);
        GS[sc_nb]->enemies[obj_i]->explosion->sprite = sfSprite_create();
        sfSprite_setTexture(GS_E[obj_i]->explosion->sprite, texture, sfFalse);
    }
    GS[sc_nb]->enemies[obj_i]->explosion->this_cl = sfClock_create();
    sfSprite_setPosition(GS_E[obj_i]->explosion->sprite, pos);
    init_intrect(&GS_E[obj_i]->explosion->anim);
}

void set_enemy(char const *line, gui_t *sc_li, int sc_nb, int obj_ind)
{
    char *info = NULL;

    if ((info = cpy_var_name("image=", line))) {
        load_text(info, sc_li, sc_nb, obj_ind);
    }
    if ((info = cpy_var_name("scale=", line))) {
        sfSprite_setScale(SCL_E[obj_ind]->sprite,
(sfVector2f){my_getfloat(info) , my_getfloat(info)});
    }
    if ((info = cpy_var_name("speed=", line))) {
        SCL_E[obj_ind]->speed = my_getfloat(info);
        info = free_char_to_null(info);
    }
    if ((info = cpy_var_name("explosion=", line))) {
        load_explosion(info, sc_li, sc_nb, obj_ind);
    }
    if ((info = cpy_var_name("size_tot", line))) {
        SCL_E[obj_ind]->explosion->size_tot_image = my_getnbr(info);
        info = free_char_to_null(info);
    }
}
