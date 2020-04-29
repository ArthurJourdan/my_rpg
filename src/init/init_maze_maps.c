/*
** EPITECH PROJECT, 2020
** init_maze_maps.c
** File description:
** initialize the maze_map strust
*/

#include "my_rpg.h"

void init_maze_map(global_t *global)
{
    char **temp = maze_main(GGM);

    GGLDM = malloc(sizeof(char *) * (GGM + 1));
    GGLMM = malloc(sizeof(maze_map_t *) * GGM);
    for (int i = 0; i != GGM; i++) {
        GGLDM[i] = malloc(sizeof(char) * (GGM + 1));
        GGLMM[i] = malloc(sizeof(maze_map_t) * GGM);
        for (int j = 0; j != GGM; j++) {
            GGLDM[i][j] = temp[i + 2][j + 2];
        }
        GGLDM[i][GGM] = '\0';
    }
    GGLDM[GGM] = NULL;
    for (size_t i = 0; GGLDM[i]; i++) {
        for (size_t j = 0; GGLDM[i][j]; j++)
            printf("%c", GGLDM[i][j]);
        printf("\n");
    }
}
