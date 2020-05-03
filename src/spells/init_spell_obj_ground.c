/*
** EPITECH PROJECT, 2020
** init_spell_obj
** File description:
** inits the spell objs on the ground
*/

#include "my_rpg.h"
#include "rpg_structs.h"
#include "sfml_tools.h"

void init_spell_text(s_obj_g *obj_ground)
{
    obj_ground->show_text = 0;
    obj_ground->pickup_text = create_text(NULL, (char * const)pickup_sen,
    (char * const)font_path, text_size);
    obj_ground->replace_text = create_text(NULL, (char * const)replace_sen,
    (char * const)font_path, text_size);
}

static void init_sp_obj(global_t *global, int arr_len, sfVector2f s_pos)
{
    for (int i = 0; i < arr_len; i++) {
        GGO->sp_obj_g[i].active = 1;
        GGO->sp_obj_g[i].id = GGS[i]->id;
        GGO->sp_obj_g[i].image = sfSprite_copy(GGS[i]->spell_img);
        GGO->sp_obj_g[i].collider = malloc(sizeof(sfIntRect));
        GGO->sp_obj_g[i].collider->left = s_pos.x;
        GGO->sp_obj_g[i].collider->top = s_pos.y;
        GGO->sp_obj_g[i].collider->width = OBJ_SIZE;
        GGO->sp_obj_g[i].collider->height = OBJ_SIZE;
    }
}

void init_spell_obj_g(global_t *global)
{
    sfVector2f s_pos = {500, 500};
    int arr_len = -1;

    if (!GGS) {
        GGO = NULL;
        return;
    }
    while (GGS[++arr_len]);
    GGO->sp_obj_g = malloc(sizeof(s_obj_g) * arr_len);
    init_spell_text(&GGO->sp_obj_g[0]);
    init_sp_obj(global, arr_len, s_pos);
    GGO->sp_obj_g[arr_len - 1].id = -1;
}
