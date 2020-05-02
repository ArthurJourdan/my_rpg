/*
** EPITECH PROJECT, 2020
** init_layers.c
** File description:
** initialize layers and collision image
*/

#include "my_rpg.h"
#include "sfml_tools.h"

static const char *WALL = "assets_rpg/images/walls/wall.png";
static const sfVector2f WALL_ORIGIN = {55.0f, 55.0f};

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
            if (GGLDM[i][j] == '*') {
                GGLMM[i][j].is_enemies = true;
                GGLMM[i][j].spawn = true;
            } else {
                GGLMM[i][j].is_enemies = false;
                GGLMM[i][j].spawn = false;
            }
            if (GGLDM[i][j] == 'X')
                GGLMM[i][j].is_open = false;
            else
                GGLMM[i][j].is_open = true;
            first_last_map(global, i, j, mazenb);
            mazenb = rand() % 7;
        }
    }
}

void init_walls(global_t *global)
{
    sfTexture *texture = sfTexture_createFromFile(WALL, NULL);

    GGL.wall = malloc(sizeof(sfSprite *) * 4);
    for (int i = 0; i != 4; i++) {
        GGL.wall[i] = sfSprite_create();
        sfSprite_setTexture(GGL.wall[i], texture, false);
        sfSprite_setOrigin(GGL.wall[i], WALL_ORIGIN);
        if (i == 0)
            sfSprite_setPosition(GGL.wall[i], sfV2F{60, GGH / 2});
        if (i == 1)
            sfSprite_setPosition(GGL.wall[i], sfV2F{GGW / 2, GGH - 60});
        if (i == 2)
            sfSprite_setPosition(GGL.wall[i], sfV2F{GGW - 60, GGH / 2});
        if (i == 3)
            sfSprite_setPosition(GGL.wall[i], sfV2F{GGW / 2, 60});
    }
}

void init_layers(global_t *global)
{
    GGL.pos = (sfVector2i){0, 0};
    init_maze_map(global);
    init_maps_sprites(global);
    init_walls(global);
}
