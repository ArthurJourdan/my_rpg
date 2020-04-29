/*
** EPITECH PROJECT, 2020
** displayer.c
** File description:
** display maze board
*/

#include "maze.h"

void print_maze(char **maze, int x, int y)
{
    for (int i = 2; maze[i + 2]; i++) {
        write(1, maze[i] + 2, x);
        if (i != y + 1)
            write(1, "\n", 1);
    }
}

void conditional_print(char **maze, int i, int j, vect2i size)
{
    if (maze[i][j] == 'X' && (i != 1 || j != 2) &&
        (i != size.x || j != size.y - 1)) {
        dprintf(2, "%s %s", BLACK, DEFAULT);
    } else if (maze[i][j] == 'o')
        dprintf(2, "%s %s", RED, DEFAULT);
    if (maze[i][j] == '*' && (
            maze[i + 1][j] == '+' || maze[i][j + 1] == '+' ||
            maze[i - 1][j] == '+' || maze[i][j - 1] == '+')) {
        dprintf(2, "%s %s", WHITE, DEFAULT);
    } else if (maze[i][j] == '*')
        dprintf(2, "%s %s", BLUE, DEFAULT);
    if (maze[i][j] == 'O') {
        dprintf(2, "%s %s", RED, DEFAULT);
    } else if (maze[i][j] == '.')
        dprintf(2, "%s %s", WHITE, DEFAULT);
    if (maze[i][j] == '+') {
        dprintf(2, "%s %s", WHITE, DEFAULT);
    }
    if ((i == 1 && j == 2) || (i == size.x && j == size.y - 1))
        dprintf(2, "%s %s", WHITE, DEFAULT);
}

void print_colored_maze(char **maze)
{
    int len = 0;
    int col = 0;

    for (int i = 1; maze[i + 1]; i++) {
        col = 0;
        for (int j = 1; maze[i + 1][j + 1]; j++)
            col++;
        len++;
    }
    dprintf(2, "\e[H\n");
    for (int i = 1; maze[i + 1]; i++) {
        for (int j = 1; maze[i + 1][j + 1]; j++)
            conditional_print(maze, i, j, (vect2i){len, col});
        if (i != len)
            dprintf(2, "\n");
    }
    dprintf(2, "\n\n");
}
