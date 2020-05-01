/*
** EPITECH PROJECT, 2020
** pixels_destroy.c
** File description:
** destroy framebuffer and all pixels
*/

#include "my_rpg.h"

void pixels_destroy(global_t *global)
{
    free(GGPS(0));
    free(GGPP(0));
    free(GGPE(0));
    free(GGPX(0));
    free(GGPS(1));
    free(GGPP(1));
    free(GGPE(1));
    free(GGPX(1));
    free(GG.pixel);
    free(GGF->pixels);
    free(GGF);
}
