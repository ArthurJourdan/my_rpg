/*
** EPITECH PROJECT, 2020
** pathfinder.c
** File description:
** find a random path
*/

#include "maze.h"

static int mystrlen(char *str)
{
    int counter = 0;

    while (str[counter])
        counter++;
    return counter;
}

int geta_random_path(char **maze, vect2i *pos)
{
    int move = 0;
    char list[4] = {'\0'};

    if (NORTH(2) == '.')
        list[move++] = '0';
    if (EAST(2) == '.')
        list[move++] = '1';
    if (SOUTH(2) == '.')
        list[move++] = '2';
    if (WEST(2) == '.')
        list[move] = '3';
    return (list[rand() % mystrlen(list)] - '0');
}

vect2i pathfinder(char **maze, vect2i *pos)
{
    int rd = geta_random_path(maze, pos);
    vect2i new_pos;

    if (rd == 0) {
        NORTH(1) = '*';
        new_pos = ((vect2i){pos->x - 2, pos->y});
    } else if (rd == 1) {
        EAST(1) = '*';
        new_pos = ((vect2i){pos->x, pos->y + 2});
    }
    if (rd == 2) {
        SOUTH(1) = '*';
        new_pos = ((vect2i){pos->x + 2, pos->y});
    } else if (rd == 3) {
        WEST(1) = '*';
        new_pos = ((vect2i){pos->x, pos->y - 2});
    }
    return new_pos;
}
