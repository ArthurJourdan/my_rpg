/*
** EPITECH PROJECT, 2020
** init_maze_maps.c
** File description:
** initialize the maze_map strust
*/

#include "my_rpg.h"
#include "print.h"

void init_maze_map(global_t *global)
{
    char **temp = NULL;

    maze_main(GGM, &temp);
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
    my_dprintf(1, "%@\n", GGLDM);
    for (size_t i = 0; temp[i]; i++)
        free(temp[i]);
    free(temp);
}
