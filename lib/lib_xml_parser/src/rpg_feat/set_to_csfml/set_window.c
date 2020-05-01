/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** set_window.c
*/

#include "my.h"
#include "gui.h"
#include "shorting_defines.h"
#include "file.h"
#include "xml_parser.h"

static sfVideoMode set_size_video_mode(char const *line)
{
    sfVideoMode video_mode;
    sfVector2f dimension = get_dimensions(line);
    int bpp = 32;

    if (cpy_var_int("bpp=", line) > 0)
        bpp = cpy_var_int("bpp=", line);
    video_mode.bitsPerPixel = bpp;
    video_mode.width = dimension.x;
    video_mode.height = dimension.y;
    return video_mode;
}

static sfRenderWindow *set_window(char const *line)
{
    sfRenderWindow *window = NULL;
    sfVideoMode video_mode = set_size_video_mode(line);
    bool fullscreen = cpy_var_bool(" fullscreen=", line);

    if (fullscreen) {
        window = sfRenderWindow_create(video_mode, "Win", sfFullscreen, NULL);
    } else
        window = sfRenderWindow_create(video_mode, "Win", sfDefaultStyle, NULL);
    return (window);
}

sfRenderWindow *init_window(char const **file)
{
    sfRenderWindow *window = NULL;
    ssize_t position = get_pos_word_in_arr("Window ", file);

    if (position != -1) {
        window = set_window(file[position]);
        return window;
    } else
        return NULL;
}
