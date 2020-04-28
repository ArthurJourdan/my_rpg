/*
** EPITECH PROJECT, 2020
** maze.h
** File description:
** mazetypes
*/

#ifndef MAZE_H
#define MAZE_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define UNSD __attribute__((unused))
#define BONUS (false)

#define DEFAULT "\e[0;00m"
#define BLACK   "\e[7;30m"
#define RED     "\e[7;31m"
#define GREEN   "\e[7;32m"
#define YELLOW  "\e[7;33m"
#define BLUE    "\e[7;34m"
#define MAGENTA "\e[7;35m"
#define TEAL    "\e[7;36m"
#define WHITE   "\e[7;37m"

#define NORTH(a) (maze[pos->x - a][pos->y])
#define SOUTH(a) (maze[pos->x + a][pos->y])
#define EAST(a)  (maze[pos->x][pos->y + a])
#define WEST(a)  (maze[pos->x][pos->y - a])

#define MAX(a, b)  ((a > b) ? a : b)

typedef struct {
    int x;
    int y;
} vect2i;

typedef struct {
    float x;
    float y;
} vect2f;

/*generator*/
char **maze_main(void);

//init_maze.c
void destroy_maze(char **maze, vect2i *stack);
char put_maze(int line, int col, int line_max, int col_max);
char **init_maze(int lines, int columns);
vect2i *init_stack(int lines, int columns);

//tools.c
void imperfect(char **maze, int i);
void put_last_maze(char **maze, vect2i last);
void last_solv(char **maze, vect2i last);
bool is_number(char const *str);
bool on_errors(int ac, char *av[]);

//backtracking.c
bool can_move(char **maze, vect2i *pos);
void anim(char **maze, int timer, vect2i *pos);
void maze_maker(char **maze, vect2i *stack, int pos, bool show);

//pathfinder.c
int geta_random_path(char **maze, vect2i *pos);
vect2i pathfinder(char **maze, vect2i *pos);

//displayer.c
void conditional_print(char **maze, int i, int j, vect2i size);
void print_maze(char **maze, int x, int y);
void print_colored_maze(char **maze);

#endif /*MAZE_H*/
