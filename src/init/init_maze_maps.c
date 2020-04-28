/*
** EPITECH PROJECT, 2020
** init_maze_maps.c
** File description:
** initialize the maze_map strust
*/

#include "my_rpg.h"

void init_maze_map(global_t *global)
{
    char **temp = maze_main();

    GGLDM = malloc(sizeof(char *) * 8);
    GGLMM = malloc(sizeof(maze_map_t *) * 7);
    for (int i = 0; i != 7; i++) {
        GGLDM[i] = malloc(sizeof(char) * 8);
        GGLMM[i] = malloc(sizeof(maze_map_t) * 7);
        for (int j = 0; j != 7; j++) {
            GGLDM[i][j] = temp[i + 2][j + 2];
        }
        GGLDM[i][7] = '\0';
    }
    GGLDM[7] = NULL;
    for (size_t i = 0; GGLDM[i]; i++) {
        for (size_t j = 0; GGLDM[i][j]; j++)
            printf("%c", GGLDM[i][j]);
        printf("\n");
    }
}
