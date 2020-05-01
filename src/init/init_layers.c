/*
** EPITECH PROJECT, 2020
** init_layers.c
** File description:
** initialize layers and collision image
*/

#include "my_rpg.h"

void my_putsprite(sfSprite **sprite, char *filepath)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    sfSprite_setTexture(*sprite, texture, false);
}

static void first_last_map(global_t *global, int i, int j, int mazenb)
{
    if (GGLDM[i][j] == 'A') {
        GGLMM[i][j].lay1 = sfSprite_copy(GM[8]->layers1[0]);
        GGLMM[i][j].lay2 = sfSprite_copy(GM[8]->layers2[0]);
        GGLMM[i][j].coll = sfImage_copy(GM[8]->colision);
        GGLMM[i][j].weather = 2;
    } else if (GGLDM[i][j] == 'D') {
        GGLMM[i][j].lay1 = sfSprite_copy(GM[7]->layers1[0]);
        GGLMM[i][j].lay2 = sfSprite_copy(GM[7]->layers2[0]);
        GGLMM[i][j].coll = sfImage_copy(GM[7]->colision);
        GGLMM[i][j].weather = 2;
    } else {
        GGLMM[i][j].lay1 = sfSprite_copy(GM[mazenb]->layers1[0]);
        GGLMM[i][j].lay2 = sfSprite_copy(GM[mazenb]->layers2[0]);
        GGLMM[i][j].coll = sfImage_copy(GM[mazenb]->colision);
        GGLMM[i][j].weather = rand() % 6;
    }
}

static void init_maps_sprites(global_t *global)
{
    int mazenb = rand() % 7;

    for (int i = 0; GGLDM[i]; i++) {
        for (int j = 0; GGLDM[i][j]; j++) {
            if (GGLDM[i][j] == '*')
                GGLMM[i][j].is_enemies = true;
            else
                GGLMM[i][j].is_enemies = false;
            if (GGLDM[i][j] == 'X')
                GGLMM[i][j].is_open = false;
            else
                GGLMM[i][j].is_open = true;
            first_last_map(global, i, j, mazenb);
            mazenb = rand() % 7;
        }
    }
}

void init_layers(global_t *global)
{
    GGL.pos = (sfVector2i){0, 0};
    init_maze_map(global);
    init_maps_sprites(global);
}
