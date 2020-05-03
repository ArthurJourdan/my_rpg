/*
** EPITECH PROJECT, 2020
** pixel_form.c
** File description:
** put some pixels on the window
*/

#include "sfml_tools.h"
#include "my_rpg.h"

void put_pixel(global_t *global, UI x, UI y, sfColor color)
{
    int move = 4 * GGW * (y - 1) + 4 * x;

    if (y > 0 && x > 0 && y < GGH && x < GGW) {
        GGF->pixels[0 + move] = color.r;
        GGF->pixels[1 + move] = color.g;
        GGF->pixels[2 + move] = color.b;
        GGF->pixels[3 + move] = color.a;
    }
}

void put_square(global_t *global, sfVector2f pos,
sfVector2f size, sfColor color)
{
    if ((int)size.x % 2)
        size.x++;
    if ((int)size.y % 2)
        size.y++;
    for (int i = - size.y / 2; i != size.y / 2; i++)
        for (int j = - size.x / 2; j != size.x / 2; j++)
            put_pixel(global, j + (UI)pos.x, i + (UI)pos.y, color);
}

void put_disc(global_t *global, sfVector2f pos, UI radius, sfColor color)
{
    for (int i = pos.y - radius; i <= pos.y + radius; i++)
        for (int j = pos.x - radius; j <= pos.x + radius; j++)
            if ((j - pos.x) * (j - pos.x) +
                (i - pos.y) * (i - pos.y) < (radius * radius))
                put_pixel(global, j, i, color);
}

void put_circle(global_t *global, sfVector2f pos, UI radius, sfColor color)
{
    int move = 4 * radius;

    for (unsigned int h = 0; h <= radius; h++) {
        put_pixel(global, h + pos.x, radius + pos.y, color);
        put_pixel(global, radius + pos.x, h + pos.y, color);
        put_pixel(global, -h + pos.x, radius + pos.y, color);
        put_pixel(global, -radius + pos.x, h + pos.y, color);
        put_pixel(global, h + pos.x, -radius + pos.y, color);
        put_pixel(global, radius + pos.x, -h + pos.y, color);
        put_pixel(global, -h + pos.x, -radius + pos.y, color);
        put_pixel(global, -radius + pos.x, -h + pos.y, color);
        if (move > 0) {
            radius--;
            move -= 8 * radius;
        }
        move += 8 * h + 4;
    }
}
