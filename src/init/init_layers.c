/*
** EPITECH PROJECT, 2020
** init_layers.c
** File description:
** initialize layers and collision image
*/

#include "my_rpg.h"

static const char LAYER1[47] = "assets_rpg/images/maps/donjon_3/donjon_3_l1.png";
static const char LAYER2[47] = "assets_rpg/images/maps/donjon_3/donjon_3_l2.png";
static const char COLLISION[47] = "assets_rpg/images/maps/donjon_3/donjon_3_lc.png";

void my_putsprite(sfSprite **sprite, char *filepath)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    sfSprite_setTexture(*sprite, texture, false);
}

void my_putmap(global_t *global, char *layer1, char *layer2, char *coll)
{
    my_putsprite(&GGL.layer1, layer1);
    my_putsprite(&GGL.layer2, layer2);
    GGL.collision = sfImage_createFromFile(coll);
}

void put_into_map(global_t *global)
{
    GGL.maps[0][0] = my_strcpy((char *)"assets_rpg/images/maps/donjon_1/donjon_1_l1.png");
    GGL.maps[0][1] = my_strcpy((char *)"assets_rpg/images/maps/donjon_2/donjon_2_l1.png");
    GGL.maps[0][2] = my_strcpy((char *)"assets_rpg/images/maps/donjon_3/donjon_3_l1.png");
    GGL.maps[0][3] = my_strcpy((char *)"assets_rpg/images/maps/donjon_4/donjon_4_l1.png");
    GGL.maps[0][4] = my_strcpy((char *)"assets_rpg/images/maps/donjon_5/donjon_5_l1.png");
    GGL.maps[0][5] = my_strcpy((char *)"assets_rpg/images/maps/donjon_6/donjon_6_l1.png");
    GGL.maps[0][6] = my_strcpy((char *)"assets_rpg/images/maps/donjon_7/donjon_7_l1.png");

    GGL.maps[1][0] = my_strcpy((char *)"assets_rpg/images/maps/donjon_1/donjon_1_l2.png");
    GGL.maps[1][1] = my_strcpy((char *)"assets_rpg/images/maps/donjon_2/donjon_2_l2.png");
    GGL.maps[1][2] = my_strcpy((char *)"assets_rpg/images/maps/donjon_3/donjon_3_l2.png");
    GGL.maps[1][3] = my_strcpy((char *)"assets_rpg/images/maps/donjon_4/donjon_4_l2.png");
    GGL.maps[1][4] = my_strcpy((char *)"assets_rpg/images/maps/donjon_5/donjon_5_l2.png");
    GGL.maps[1][5] = my_strcpy((char *)"assets_rpg/images/maps/donjon_6/donjon_6_l2.png");
    GGL.maps[1][6] = my_strcpy((char *)"assets_rpg/images/maps/donjon_7/donjon_7_l2.png");

    GGL.maps[2][0] = my_strcpy((char *)"assets_rpg/images/maps/donjon_1/donjon_1_lc.png");
    GGL.maps[2][1] = my_strcpy((char *)"assets_rpg/images/maps/donjon_2/donjon_2_lc.png");
    GGL.maps[2][2] = my_strcpy((char *)"assets_rpg/images/maps/donjon_3/donjon_3_lc.png");
    GGL.maps[2][3] = my_strcpy((char *)"assets_rpg/images/maps/donjon_4/donjon_4_lc.png");
    GGL.maps[2][4] = my_strcpy((char *)"assets_rpg/images/maps/donjon_5/donjon_5_lc.png");
    GGL.maps[2][5] = my_strcpy((char *)"assets_rpg/images/maps/donjon_6/donjon_6_lc.png");
    GGL.maps[2][6] = my_strcpy((char *)"assets_rpg/images/maps/donjon_7/donjon_7_lc.png");
}

void init_maps_sprites(global_t *global)
{
    GGL.maps = malloc(sizeof(char **) * 4);
    GGL.maps[3] = NULL;
    for (size_t i = 0; i != 3; i++) {
        GGL.maps[i] = malloc(sizeof(char *) * 8);
        GGL.maps[i][7] = NULL;
    }
    put_into_map(global);
}

void init_layers(global_t *global)
{
    GGL.layer1 = sfSprite_create();
    GGL.layer2 = sfSprite_create();
    my_putmap(global, (char *)LAYER1, (char *)LAYER2, (char *)COLLISION);
    GGL.nb = 3;
    init_maps_sprites(global);
    init_maze_map(global);
}
