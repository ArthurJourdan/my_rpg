/*
** EPITECH PROJECT, 2020
** destroy_something.c
** File description:
** desstroy all object of the game
*/

#include "global.h"
#include "button.h"
#include "text.h"
#include "sfml_tools.h"
#include "my_rpg.h"

static void destroy_text(text_t *text)
{
    if (!text)
        return;
    if (text->name)
        free(text->name);
    if (text->string)
        free(text->string);
    if (text->text_sfml)
        sfText_destroy(text->text_sfml);
    free(text);
}
static void destroy_button(button_t *button)
{
    if (!button)
        return;
    if (button->name)
        free(button->name);
    if (button->text)
        destroy_text(button->text);
    if (button->rect)
        sfRectangleShape_destroy(button->rect);
    if (button->sound) {
        sfSound_pause(button->sound);
        sfSound_stop(button->sound);
        sfSound_destroy(button->sound);
    }
    free(button);
}

static void destroy_loops(scene_t *scene)
{
    if (scene->texts)
        for (size_t a = 0; scene->texts[a]; a++)
            destroy_text(scene->texts[a]);
    if (scene->images)
        for (size_t a = 0; scene->images[a]; a++)
            sfSprite_destroy(scene->images[a]);
    if (scene->buttons)
        for (size_t i = 0; scene->buttons[i] != NULL; i++)
            destroy_button(scene->buttons[i]);
}

static void destroy_scene(scene_t *scene)
{
    if (scene->name)
        free(scene->name);
    if (scene->music) {
        sfMusic_pause(scene->music);
        sfMusic_stop(scene->music);
        sfMusic_destroy(scene->music);
    }
    if (scene->sound) {
        sfSound_pause(scene->sound);
        sfSound_stop(scene->sound);
        sfSound_destroy(scene->sound);
    }
    destroy_loops(scene);
}

void destroy_game(global_t *global)
{
    sfRenderWindow_destroy(global->window);
    for (size_t i = 0; GS->scenes[i] != NULL; i++) {
        destroy_scene(GS->scenes[i]);
    }
    player_destroy(global);
    pixels_destroy(global);
    free(global);
}
