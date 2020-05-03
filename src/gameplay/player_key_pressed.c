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

static void key_up(global_t *global)
{
    if (sfKeyboard_isKeyPressed(GGPC.up)) {
        GGPC.on_up = true;
        GGP.sprite = GGP.ss[3][GGP.frame];
        GGPL = 3;
    } else
        GGPC.on_up = false;
}

static void key_left(global_t *global)
{
    if (sfKeyboard_isKeyPressed(GGPC.left)) {
        GGPC.on_left = true;
        GGP.sprite = GGP.ss[1][GGP.frame];
        GGPL = 0;
    } else
        GGPC.on_left = false;
}

static void key_down(global_t *global)
{
    if (sfKeyboard_isKeyPressed(GGPC.down)) {
        GGPC.on_down = true;
        GGP.sprite = GGP.ss[0][GGP.frame];
        GGPL = 1;
    } else
        GGPC.on_down = false;
}

static void key_right(global_t *global)
{
    if (sfKeyboard_isKeyPressed(GGPC.right)) {
        GGPC.on_right = true;
        GGP.sprite = GGP.ss[2][GGP.frame];
        GGPL = 2;
    } else
        GGPC.on_right = false;
}

void player_key_pressed(global_t *global)
{
    key_up(global);
    key_left(global);
    key_down(global);
    key_right(global);
}
