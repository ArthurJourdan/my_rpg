/*
** EPITECH PROJECT, 2020
** player_movement.c
** File description:
** player movements manager
*/

#include <SFML/Window/Export.h>
#include <SFML/Window/Keyboard.h>
#include <math.h>
#include "my_rpg.h"
#include "sfml_tools.h"

static const float offset = 55.0f;

static void up(global_t *global)
{
    if (GGPC.on_up && !GGPC.on_left && !GGPC.on_down && !GGPC.on_right &&
        ((GGLP.y > 0 && GGLMM[GGLP.y - 1][GGLP.x].is_open) ||
        GGP.pos.y > sfSprite_getPosition(GGL.wall[3]).y + offset)) {
        GGP.pos.y -= GGP.speed;
    }
}

static void left(global_t *global)
{
    if (!GGPC.on_up && GGPC.on_left && !GGPC.on_down && !GGPC.on_right &&
        ((GGLP.x > 0 && GGLMM[GGLP.y][GGLP.x - 1].is_open) ||
        GGP.pos.x > sfSprite_getPosition(GGL.wall[0]).x + offset)) {
        GGP.pos.x -= GGP.speed;
    }
}

static void down(global_t *global)
{
    if (!GGPC.on_up && !GGPC.on_left && GGPC.on_down && !GGPC.on_right &&
        ((GGLP.y < (GGM - 1) && GGLMM[GGLP.y + 1][GGLP.x].is_open) ||
        GGP.pos.y < sfSprite_getPosition(GGL.wall[1]).y - offset)) {
        GGP.pos.y += GGP.speed;
    }
}

static void right(global_t *global)
{
    if (!GGPC.on_up && !GGPC.on_left && !GGPC.on_down && GGPC.on_right &&
        ((GGLP.x < (GGM - 1) && GGLMM[GGLP.y][GGLP.x + 1].is_open) ||
        GGP.pos.x < sfSprite_getPosition(GGL.wall[2]).x - offset)) {
        GGP.pos.x += GGP.speed;
    }
}

void line_player_deplacement(global_t *global)
{
    up(global);
    left(global);
    down(global);
    right(global);
}
