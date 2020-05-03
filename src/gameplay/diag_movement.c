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

static void up_left(global_t *global)
{
    if (GGPC.on_up && GGPC.on_left &&
        ((GGLP.y > 0 && GGLMM[GGLP.y - 1][GGLP.x].is_open) ||
        GGP.pos.y > sfSprite_getPosition(GGL.wall[3]).y + offset) &&
        ((GGLP.x > 0 && GGLMM[GGLP.y][GGLP.x - 1].is_open) ||
        GGP.pos.x > sfSprite_getPosition(GGL.wall[0]).x + offset)) {
        GGP.pos.y -= sin(M_PI / 4) * GGP.speed;
        GGP.pos.x -= cos(M_PI / 4) * GGP.speed;
    }
}

static void left_down(global_t *global)
{
    if (GGPC.on_left && GGPC.on_down &&
        ((GGLP.x > 0 && GGLMM[GGLP.y][GGLP.x - 1].is_open) ||
        GGP.pos.x > sfSprite_getPosition(GGL.wall[0]).x + offset) &&
        ((GGLP.y < (GGM - 1) && GGLMM[GGLP.y + 1][GGLP.x].is_open) ||
        GGP.pos.y < sfSprite_getPosition(GGL.wall[1]).y - offset)) {
        GGP.pos.y += sin(M_PI / 4) * GGP.speed;
        GGP.pos.x -= cos(M_PI / 4) * GGP.speed;
    }
}

static void down_right(global_t *global)
{
    if (GGPC.on_down && GGPC.on_right &&
        ((GGLP.y < (GGM - 1) && GGLMM[GGLP.y + 1][GGLP.x].is_open) ||
        GGP.pos.y < sfSprite_getPosition(GGL.wall[1]).y - offset) &&
        ((GGLP.x < (GGM - 1) && GGLMM[GGLP.y][GGLP.x + 1].is_open) ||
        GGP.pos.x < sfSprite_getPosition(GGL.wall[2]).x - offset)) {
        GGP.pos.y += sin(M_PI / 4) * GGP.speed;
        GGP.pos.x += cos(M_PI / 4) * GGP.speed;
    }
}

static void right_up(global_t *global)
{
    if (GGPC.on_right && GGPC.on_up &&
        ((GGLP.x < (GGM - 1) && GGLMM[GGLP.y][GGLP.x + 1].is_open) ||
        GGP.pos.x < sfSprite_getPosition(GGL.wall[2]).x - offset) &&
        ((GGLP.y > 0 && GGLMM[GGLP.y - 1][GGLP.x].is_open) ||
        GGP.pos.y > sfSprite_getPosition(GGL.wall[3]).y + offset)) {
        GGP.pos.y -= sin(M_PI / 4) * GGP.speed;
        GGP.pos.x += cos(M_PI / 4) * GGP.speed;
    }
}

void diag_player_deplacement(global_t *global)
{
    up_left(global);
    left_down(global);
    down_right(global);
    right_up(global);
}
