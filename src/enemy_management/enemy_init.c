/*
** EPITECH PROJECT, 2020
** enemy_init.c
** File description:
** c
*/

void enemy_init(game_t *game, int id, sfVector2f pos)
{
    int i = 0;

    for (i = 0; G_E_OBJ[i]->obj_satus == true; i++);
    G_E_OBJ[i]->obj_status = true;
    G_E_OBJ[i]->id = id;
    G_E_OBJ[i]->frame = 0;
    G_E_OBJ[i]->max_hp = G_E_DICT[id]->hp;
    G_E_OBJ[i]->hp = G_E_OBJ[i]->max_hp;
    G_E_OBJ[i]->spell_nodes = G_E_DICT[id]->spell_nodes;
    G_E_OBJ[i]->speed = {0};
    G_E_OBJ[i]->pos = pos;
    G_E_OBJ[i]->collider = G_E_DICT[id]->collider;
    return;é
}
