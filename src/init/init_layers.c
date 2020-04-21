/*
** EPITECH PROJECT, 2020
** init_layers.c
** File description:
** initialize layers and collision image
*/

#include "my_rpg.h"

static const char LAYER1[47] = "assets_rpg/images/maps/donjon_3/donjon_3_l1.png";
static const char LAYER2[47] = "assets_rpg/images/maps/donjon_3/donjon_3_l2.png";
static const char COLLISION[46] = "assets_rpg/images/maps/donjon_3/donjon_3_c.png";

void my_putsprite(sfSprite **sprite, char *filepath)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    sfSprite_setTexture(*sprite, texture, false);
}

void my_putmap(layers_t *layers, char *layer1, char *layer2, char *coll)
{
    my_putsprite(&layers->layer1, layer1);
    my_putsprite(&layers->layer2, layer2);
    layers->collision = sfImage_createFromFile(coll);
}

void put_into_map(layers_t *layers)
{
    layers->maps[0][0] = my_strcpy((char *)"assets_rpg/images/maps/donjon_1/donjon_1_l1.png");
    layers->maps[0][1] = my_strcpy((char *)"assets_rpg/images/maps/donjon_2/donjon_2_l1.png");
    layers->maps[0][2] = my_strcpy((char *)"assets_rpg/images/maps/donjon_3/donjon_3_l1.png");
    layers->maps[0][3] = my_strcpy((char *)"assets_rpg/images/maps/donjon_4/donjon_4_l1.png");
    layers->maps[0][4] = my_strcpy((char *)"assets_rpg/images/maps/donjon_5/donjon_5_l1.png");
    layers->maps[0][5] = my_strcpy((char *)"assets_rpg/images/maps/donjon_6/donjon_6_l1.png");
    layers->maps[0][6] = my_strcpy((char *)"assets_rpg/images/maps/donjon_7/donjon_7_l1.png");

    layers->maps[1][0] = my_strcpy((char *)"assets_rpg/images/maps/donjon_1/donjon_1_l2.png");
    layers->maps[1][1] = my_strcpy((char *)"assets_rpg/images/maps/donjon_2/donjon_2_l2.png");
    layers->maps[1][2] = my_strcpy((char *)"assets_rpg/images/maps/donjon_3/donjon_3_l2.png");
    layers->maps[1][3] = my_strcpy((char *)"assets_rpg/images/maps/donjon_4/donjon_4_l2.png");
    layers->maps[1][4] = my_strcpy((char *)"assets_rpg/images/maps/donjon_5/donjon_5_l2.png");
    layers->maps[1][5] = my_strcpy((char *)"assets_rpg/images/maps/donjon_6/donjon_6_l2.png");
    layers->maps[1][6] = my_strcpy((char *)"assets_rpg/images/maps/donjon_7/donjon_7_l2.png");

    layers->maps[2][0] = my_strcpy((char *)"assets_rpg/images/maps/donjon_1/donjon_1_c.png");
    layers->maps[2][1] = my_strcpy((char *)"assets_rpg/images/maps/donjon_2/donjon_2_c.png");
    layers->maps[2][2] = my_strcpy((char *)"assets_rpg/images/maps/donjon_3/donjon_3_c.png");
    layers->maps[2][3] = my_strcpy((char *)"assets_rpg/images/maps/donjon_4/donjon_4_c.png");
    layers->maps[2][4] = my_strcpy((char *)"assets_rpg/images/maps/donjon_5/donjon_5_c.png");
    layers->maps[2][5] = my_strcpy((char *)"assets_rpg/images/maps/donjon_6/donjon_6_c.png");
    layers->maps[2][6] = my_strcpy((char *)"assets_rpg/images/maps/donjon_7/donjon_7_c.png");
}

void init_maps_sprites(layers_t *layers)
{
    layers->maps = malloc(sizeof(char **) * 4);
    layers->maps[3] = NULL;
    for (size_t i = 0; i != 3; i++) {
        layers->maps[i] = malloc(sizeof(char *) * 8);
        layers->maps[i][7] = NULL;
    }
    put_into_map(layers);
}

void init_layers(layers_t *layers)
{
    layers->layer1 = sfSprite_create();
    layers->layer2 = sfSprite_create();
    my_putmap(layers, (char *)LAYER1, (char *)LAYER2, (char *)COLLISION);
    layers->nb = 3;
    init_maps_sprites(layers);
}
