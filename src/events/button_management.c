/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** button_management.c
*/

#include "events.h"
#include "button.h"
#include "sfml_tools.h"

static int is_button_pressed(global_t *global)
{
    sfVector2f size_rect = {0};
    sfVector2f pos_rect = {0};
    sfVector2f mouse = get_mouse_coo(GW);

    if (!SC_B)
        return -1;
    for (int nb_button = 0; SC_B[nb_button]; nb_button++) {
        pos_rect = sfRectangleShape_getPosition(SC_B[nb_button]->rect);
        size_rect = sfRectangleShape_getSize(SC_B[nb_button]->rect);
        if (mouse.x > pos_rect.x && mouse.x < pos_rect.x + size_rect.x) {
            if (mouse.y > pos_rect.y && mouse.y < pos_rect.y + size_rect.y) {
                return nb_button;
            }
        }
    }
    return -1;
}

static void change_button_state(button_t *button, unsigned short state)
{
    if (state == IDLE) {
        sfRectangleShape_setOutlineColor(button->rect, button->idle_color);
        if (button->nb_animations) {
            next_texture_rect_shape(button->rect, button->nb_animations,
            button->size_tot, 0);
        }
    } if (state == HOVER) {
        sfRectangleShape_setOutlineColor(button->rect, button->hover_color);
        if (button->nb_animations && button->nb_animations > 1) {
            next_texture_rect_shape(button->rect, button->nb_animations,
            button->size_tot, 1);
        }
    } if (state == CLICKED) {
        sfRectangleShape_setOutlineColor(button->rect, button->clicked_color);
        if (button->nb_animations && button->nb_animations > 2) {
            next_texture_rect_shape(button->rect, button->nb_animations,
            button->size_tot, 2);
        }
    }
}

static void activate_button(global_t *global, button_t *button, sfEvent event)
{
    if (left_mouse_released(event) ) {
        if (button && button->sound) {
            sfSound_play(button->sound);
        }
        if (button->action)
            button->action(global);
    } else {
        change_button_state(button, CLICKED);
    }
}

bool button_management(global_t *global, sfEvent event)
{
    int nb_button = -1;

    if ((nb_button = is_button_pressed(global)) != -1) {
        change_button_state(SC_B[nb_button], HOVER);
        if (left_mouse_pressed(event) || left_mouse_released(event)) {
            activate_button(global, SC_B[nb_button], event);
        }
    }
    if (!SC_B)
        return false;
    for (int a = 0; SC_B[a]; a++) {
        if (a != nb_button) {
            change_button_state(SC_B[a], IDLE);
        }
    }
    return false;
}
