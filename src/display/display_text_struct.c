/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** display_text.c
*/

#include "my.h"
#include "text.h"
#include "sfml_tools.h"
#include "global.h"
#include "shorting_defines.h"

static void draw_delay_letter(text_t *text, size_t count_time, size_t fps)
{
    size_t letter_per_sec = count_time % (size_t)(text->letter_delay * fps) + 1;
    size_t len_string_text = 0;
    char *string_text = NULL;

    if ((float)letter_per_sec == (fps * text->letter_delay)) {
        len_string_text = my_strlen(sfText_getString(text->text_sfml)) + 1;
        string_text = my_str_n_cpy(text->string, len_string_text);
        if (string_text) {
            sfText_setString(text->text_sfml, string_text);
            free(string_text);
        }
    }
}

static void draw_delay_text(text_t *text, sfRenderWindow *window,
size_t count_time, size_t fps)
{
    if ((float)(count_time / fps) >= text->appear_delay && text->letter_delay) {
        draw_delay_letter(text, count_time, fps);
        display_one_text(window, text->text_sfml);
    } else if ((float)(count_time / fps) > text->appear_delay) {
        display_one_text(window, text->text_sfml);
    }
}

void display_text_struct(text_t *text, sfRenderWindow *window, size_t fps,
size_t count_time)
{
    if (!text || !window)
        return;
    if (text->disappear_delay && count_time / fps > text->disappear_delay)
        return;
    if (!text->timed)
        display_one_text(window, text->text_sfml);
    else
        draw_delay_text(text, window, count_time, fps);
}

void display_texts_struct(global_t *global, size_t count_time)
{
    if (SC_T) {
        for (size_t a = 0; SC_T[a]; a++) {
            display_text_struct(SC_T[a], GW, FPS, count_time);
        }
    }
    if (SC_B) {
        for (size_t b = 0; SC_B[b]; b++) {
            display_text_struct(SC_B[b]->text, GW, FPS, count_time);
        }
    }
}
