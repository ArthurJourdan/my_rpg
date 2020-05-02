/*
** EPITECH PROJECT, 2020
** backtracking.c
** File description:
** create maze board
*/

#include "maze.h"

bool can_move(char **maze, vect2i *pos)
{
    if (maze[pos->x - 2][pos->y] == '.' || maze[pos->x][pos->y + 2] == '.' ||
        maze[pos->x + 2][pos->y] == '.' || maze[pos->x][pos->y - 2] == '.')
        return true;
    return false;
}

void anim(char **maze, int timer, vect2i *pos)
{
    maze[pos->x][pos->y] = 'O';
    printf("\n");
    usleep(timer);
    for (int i = 0; maze[i]; i++)
        for (int j = 0; maze[i][j]; j++)
            if (maze[i][j] == 'O')
                maze[i][j] = '*';
    if (!can_move(maze, pos))
        maze[pos->x][pos->y] = '+';
}

void maze_maker(char **maze, vect2i *stack, int pos, bool show)
{
    while (pos >= 0) {
        maze[stack[pos].x][stack[pos].y] = '*';
        if (show)
            anim(maze, 7000, stack + pos);
        if (can_move(maze, stack + pos)) {
            stack[pos + 1] = pathfinder(maze, stack + pos);
            pos++;
        } else
            pos--;
    }
}
