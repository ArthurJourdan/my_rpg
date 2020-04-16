/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** button.h
*/

#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>


struct gui;
struct global_vars;

typedef struct button {
    char *name;
    sfText *text;
    sfRectangleShape *rect;
    sfSprite *sprite;
    unsigned short nb_animations;
    size_t size_tot;
    struct global_vars *(*action)(struct global_vars *);
    sfSound *sound;
} button_t;

typedef struct act_button {
    char * const name_act;
    struct global_vars *(*action)(struct global_vars *);
} actions_t;

void display_buttons(sfRenderWindow *window, button_t **buttons);

// CHANGE SCENE
void change_scene(struct gui *scene_list, int scene_nb);
struct global_vars *go_out(struct global_vars *);
struct global_vars *go_start(struct global_vars *);
struct global_vars *go_pause(struct global_vars *);
struct global_vars *go_back_to_game(struct global_vars *);
struct global_vars *go_options(struct global_vars *);
struct global_vars *go_starting_menu(struct global_vars *);
struct global_vars *volume_sounds_up(struct global_vars *);
struct global_vars *volume_sounds_down(struct global_vars *);
struct global_vars *volume_all_sounds_up(struct global_vars *);
struct global_vars *volume_all_sounds_down(struct global_vars *);
struct global_vars *volume_music_down(struct global_vars *);
struct global_vars *volume_music_up(struct global_vars *);
struct global_vars *volume_all_musics_down(struct global_vars *);
struct global_vars *volume_all_musics_up(struct global_vars *);
struct global_vars *go_htp(struct global_vars *);

enum state {
    IDLE,
    HOVER,
    CLICKED
};

 #endif /* !BUTTON_H */