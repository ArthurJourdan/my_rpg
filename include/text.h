/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** text.h
*/

#ifndef TEXT_H
#define TEXT_H

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#include <stdbool.h>

struct global_vars;

typedef struct text {
    char *name;
    char *string;
    sfText *text_sfml;
    bool timed;
    float letter_delay;
    float appear_delay;
    float disappear_delay;
} text_t;

text_t *set_any_text(char const *line, text_t *text);

void display_text_struct(text_t *text, sfRenderWindow *window, size_t fps,
size_t count_time);
void display_texts_struct(struct global_vars *global , size_t count_time);

#endif /* !TEXT_H */
