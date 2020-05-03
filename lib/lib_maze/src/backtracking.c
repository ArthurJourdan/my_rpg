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

void maze_maker(char **maze, vect2i *stack, int pos, UNSD bool show)
{
    while (pos >= 0) {
        maze[stack[pos].x][stack[pos].y] = '*';
        if (can_move(maze, stack + pos)) {
            stack[pos + 1] = pathfinder(maze, stack + pos);
            pos++;
        } else
            pos--;
    }
}
