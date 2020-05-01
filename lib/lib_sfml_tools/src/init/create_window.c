/*
** EPITECH PROJECT, 2020
** MUL_
** File description:
** create_window.c
*/

#include "sfml_tools.h"

fbuffer_t *framebuffer_create(UI width, UI height)
{
    fbuffer_t *buffer = malloc(sizeof(fbuffer_t));

    buffer->pixels = malloc(height * width * 4);
    buffer->width = width;
    buffer->height = height;

    return buffer;
}

sfRenderWindow *create_window(UI width, UI height, UI bbp, char const *name)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = bbp;
    window = sfRenderWindow_create(video_mode, name, sfDefaultStyle, NULL);
    return (window);
}

void framebuffer_destroy(fbuffer_t *buffer)
{
    free(buffer->pixels);
    free(buffer);
}
