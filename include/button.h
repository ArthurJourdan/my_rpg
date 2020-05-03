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

struct text;
struct gui;
struct global_vars;

typedef struct button {
    char *name;
    struct text *text;
    sfRectangleShape *rect;
    sfSprite *sprite;
    unsigned short nb_animations;
    size_t size_tot;
    void (*action)(struct global_vars *);
    sfSound *sound;
    sfColor idle_color;
    sfColor hover_color;
    sfColor clicked_color;
} button_t;

typedef struct action {
    char * const name_act;
    void (*action)(struct global_vars *);
} actions_t;

void display_buttons(struct global_vars *global);

// CHANGE SCENE
void change_scene(struct gui *scene_list, int scene_nb);

void go_out(struct global_vars *);
void go_start(struct global_vars *);
void go_restart(struct global_vars *);
void go_pause(struct global_vars *);
void go_back_to_game(struct global_vars *);
void go_options(struct global_vars *);
void go_starting_menu(struct global_vars *);
void volume_sounds_up(struct global_vars *);
void volume_sounds_down(struct global_vars *);
void volume_all_sounds_up(struct global_vars *);
void volume_all_sounds_down(struct global_vars *);
void volume_music_down(struct global_vars *);
void volume_music_up(struct global_vars *);
void volume_all_musics_down(struct global_vars *);
void volume_all_musics_up(struct global_vars *);
void go_htp(struct global_vars *);
void increase_fps(struct global_vars *);
void decrease_fps(struct global_vars *);

enum state {
    IDLE,
    HOVER,
    CLICKED
};

// !CHANGE SCENE

#endif /* !BUTTON_H */
