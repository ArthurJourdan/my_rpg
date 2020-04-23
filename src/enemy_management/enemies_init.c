/*
** EPITECH PROJECT, 2020
** enemies
** File description:
** init
*/

void enemy_tab_init(game_t *game)
{
    for (int i = 0; i < 64; i++) {
        G_E_OBJ[i]->obj_status = false;
        G_E_OBJ[i]->id = 0;
        G_E_OBJ[i]->frame = 0;
        G_E_OBJ[i]->max_hp = 0;
        G_E_OBJ[i]->hp = 0;
        G_E_OBJ[i]->damage = 0;
        G_E_OBJ[i]->spell_nodes = NULL;
        G_E_OBJ[i]->speed = {0};
        G_E_OBJ[i]->pos = {0};
        G_E_OBJ[i]->collider = NULL;
    }
    return;
}
