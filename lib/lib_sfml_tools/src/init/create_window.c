/*
** EPITECH PROJECT, 2020
** MUL_
** File description:
** create_window.c
*/

#include "sfml_tools.h"

sfRenderWindow *create_window(unsigned int width, unsigned int height,
unsigned int bbp, char const *name)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    if (video_mode.width > 0)
        video_mode.width = width;
    else
        video_mode.width = 1920;
    if (video_mode.height > 0)
        video_mode.height = height;
    else
        video_mode.height = 1080;
    if (bbp > 0)
        video_mode.bitsPerPixel = bbp;
    else
        video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, name, sfDefaultStyle, NULL);
    return (window);
}