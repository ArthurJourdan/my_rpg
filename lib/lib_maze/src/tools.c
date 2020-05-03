/*
** EPITECH PROJECT, 2020
** maze_tool.c
** File description:
** push pop and len of the stack
*/

#include "maze.h"

void imperfect(char **maze, int i)
{
    for (int j = 2; maze[i + 2][j + 2]; j++)
        if (maze[i][j] == 'X' && !(rand() % 12))
            maze[i][j] = '*';
}

void put_last_maze(char **maze, vect2i last)
{
    for (size_t i = 0; maze[i]; i++)
        for (size_t j = 0; maze[i][j]; j++)
            if (maze[i][j] == '+')
                maze[i][j] = '*';
    if (!(last.x % 2) || !(last.y % 2))
        maze[last.x + 1][last.y + 1] = '*';
    if (!(last.x % 2) && !(last.y % 2))
        maze[last.x + 1][last.y] = '*';
    for (int i = 2; maze[i + 2]; i++)
        imperfect(maze, i);
    maze[2][2] = 'D';
    maze[last.x + 1][last.y + 1] = 'A';
}

void last_solv(char **maze, vect2i size)
{
    if (!(size.x % 2) || !(size.y % 2))
        maze[size.y + 1][size.x + 1] = 'o';
    if (!(size.x % 2) && !(size.y % 2))
        maze[size.y + 1][size.x] = 'o';
    for (size_t i = 0; maze[i]; i++)
        for (size_t j = 0; maze[i][j]; j++) {
            if (maze[i][j] == '.')
                maze[i][j] = '*';
            if (maze[i][j] == '+')
                maze[i][j] = 'o';
        }
}

bool is_number(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return false;
    return true;
}