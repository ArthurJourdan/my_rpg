/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main of proto's star project
*/

#include "maze.h"

char **maze_main(void)
{
    char **maze;
    vect2i size;
    vect2i *stack;

    size = (vect2i){7, 7};
    maze = init_maze(size.y, size.x);
    stack = init_stack(size.y, size.x);
    maze_maker(maze, stack, 0, false);
    put_last_maze(maze, (vect2i){size.y, size.x});
//    print_maze(maze, size.x, size.y);
//    destroy_maze(maze, stack);
    return maze;
}
