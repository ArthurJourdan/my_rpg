/*
** EPITECH PROJECT, 2020
** SFML lib
** File description:
** sfml_tools.h
*/

#ifndef SFML_TOOLS_H
#define SFML_TOOLS_H

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#include <stdlib.h>
#include <stdbool.h>
#include "my_rpg.h"

#define UI unsigned int
#define sfC (sfColor)
#define sfV2F (sfVector2f)

typedef struct sfml_colors {
    sfColor sf_color;
    char * const str_color;
} sfml_colors_t;

// WINDOW
fbuffer_t *framebuffer_create(UI width, UI height);
sfRenderWindow *create_window(UI width, UI height, UI bbp, char const *name);
void framebuffer_destroy(fbuffer_t *buffer);
// !WINDOW

//PIXELS
void put_pixel(global_t *global, UI x, UI y, sfColor color);
void put_square(global_t *global, sfVector2f pos,
sfVector2f size, sfColor color);
void put_circle(global_t *global, sfVector2f pos, UI radius, sfColor color);
void put_disc(global_t *global, sfVector2f pos, UI radius, sfColor color);
// !PIXELS

// SPRITE
sfSprite *create_image(sfSprite *sprite, char const *filepath);
sfSprite *create_image_fullscreen(sfSprite *sprite, sfRenderWindow *window,
char const *filepath);

void set_sprite_fullscreen(sfRenderWindow *window, sfSprite *sprite);
void set_sprite_arr_fullscreen(sfRenderWindow *window, sfSprite **sprites);

void display_one_sprite(sfRenderWindow *window, sfSprite *sprite);
void display_images(sfRenderWindow *window, sfSprite **images);
// !SPRITE

// RECTANGLESHAPE
sfRectangleShape *create_rectshape(sfRectangleShape *rect, sfVector2f size);

void add_texture_rectshape(sfRectangleShape *rect, char *filepath);
void set_rectshape_color(sfRectangleShape *rectshape,

sfColor in, sfColor out, float outline_thickness);

void set_texture_rect_shape(sfRectangleShape *rect_shape,
unsigned short nb_animations, size_t size_tot);
void next_texture_rect_shape(sfRectangleShape *rect_shape,
unsigned short nb_animations, size_t size_tot, size_t anim_wanted);
// !RECTANGLESHAPE

// TEXT
sfText *create_text(sfText *text, char * const str, char * const
font, int size);

void display_texts(sfRenderWindow *window, sfText **texts);
void display_one_text(sfRenderWindow *window, sfText *text);
// !TEXT

// SOUND
sfSound *create_sound(sfSound *sound, char *file, float volume, bool loop);

void change_sound_volume(sfSound *sound, float increase);
void set_sound_volume(sfSound *sound, float volume);
// !SOUND

// MUSIC
sfMusic *create_music(sfMusic *music, char *file, float volume, bool loop);

void set_music_volume(sfMusic *music, float volume);
void change_music_volume(sfMusic *music, float increase);
// !MUSIC

// EVENTS
sfVector2f get_mouse_coo(sfRenderWindow *win);
bool left_mouse_pressed(sfEvent event);
bool right_mouse_pressed(sfEvent event);
bool left_mouse_released(sfEvent event);
bool right_mouse_released(sfEvent event);

// !EVENTS

// COLOR
sfColor get_color_from_str(char * const str);
// !COLOR

#endif /* !SFML_TOOLS_H */
