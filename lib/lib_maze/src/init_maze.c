/*
** EPITECH PROJECT, 2020
** init_maze.c
** File description:
** init maze board
*/

#include "maze.h"

void destroy_maze(char **maze, vect2i *stack)
{
    for (int i = 0; maze[i]; i++)
        free(maze[i]);
    free(maze);
    free(stack);
}

char put_maze(int line, int col, int line_max, int col_max)
{
    char c = '\0';

    if (!line || !col || line == line_max + 1 || col == col_max + 1 ||
        line == 1 || col == 1 || line == line_max + 2 || col == col_max + 2)
        c = 'X';
    if (line > 1 && col > 1 && line < line_max + 1 && col < col_max + 1)
        c = '.';
    if (line % 2 || col % 2)
        c = 'X';
    return c;
}

char **init_maze(int lines, int columns)
{
    char **maze = malloc(sizeof(char *) * (lines + 5));

    srand(time(NULL));
    for (int i = 0; i != lines + 4; i++) {
        maze[i] = malloc(sizeof(char) * (columns + 5));
        for (int j = 0; j != columns + 4; j++)
            maze[i][j] = put_maze(i, j, lines + 1, columns + 1);
        maze[i][columns + 4] = '\0';
    }
    maze[lines + 4] = NULL;
    return maze;
}

vect2i *init_stack(int lines, int columns)
{
    int real_lines = lines + 5;
    int real_columns = columns + 5;
    int len = real_lines * real_columns + 1;
    vect2i *stack = malloc(sizeof(vect2i) * len);

    stack[0] = (vect2i){2, 2};
    return stack;
}
