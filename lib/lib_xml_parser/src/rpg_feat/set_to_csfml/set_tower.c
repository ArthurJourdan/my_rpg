/*
** EPITECH PROJECT, 2020
** MUL_my_runner
** File description:
** set_tower.c
*/

#include "my.h"
#include "gui.h"
#include "shorting_defines.h"
#include "xml_parser.h"

static void load_text(char *info, gui_t *sc_li, int sc_nb, int obj_i)
{
    sfTexture *texture = NULL;
    sfVector2f pos = {-1000, -1000};

    texture = sfTexture_createFromFile(info, NULL);
    info = free_char_to_null(info);
    sfSprite_setTexture(SCL_TOW[obj_i]->sprite, texture,
    sfFalse);
    sfSprite_setPosition(SCL_TOW[obj_i]->sprite, pos);
}

static void load_explosion(char *info, gui_t *sc_li, int sc_nb, int idx)
{
    sfTexture *texture = NULL;
    sfVector2f pos = {-1000, -1000};

    if (info) {
        texture = sfTexture_createFromFile(info, NULL);
        info = free_char_to_null(info);
        SCL_TOW[idx]->explosion->sprite = sfSprite_create();
        sfSprite_setTexture(SCL_TOW[idx]->explosion->sprite, texture, sfFalse);
    }
    SCL_TOW[idx]->explosion->this_cl = sfClock_create();
    sfSprite_setPosition(SCL_TOW[idx]->explosion->sprite, pos);
}

void set_tower(char const *line, gui_t *sc_li, int sc_nb, int obj_ind)
{
    char *info = NULL;

    if ((info = cpy_var_name("image=", line))) {
        load_text(info, sc_li, sc_nb, obj_ind);
    }
    if ((info = cpy_var_name("scale=", line))) {
        sfSprite_setScale(SCL_TOW[obj_ind]->sprite,
        (sfVector2f){my_getfloat(info) *10, my_getfloat(info) * 10});
    }
    if ((info = cpy_var_name("explosion=", line))) {
        load_explosion(info, sc_li, sc_nb, obj_ind);
    }
    if ((info = cpy_var_name("nb_animations", line))) {
        SCL_TOW[obj_ind]->explosion->
        nb_animation = my_getnbr(info);
        info = free_char_to_null(info);
    }
    if ((info = cpy_var_name("size_tot", line))) {
        SCL_TOW[obj_ind]->explosion->size_tot_image = my_getnbr(info);
        info = free_char_to_null(info);
    }
}
