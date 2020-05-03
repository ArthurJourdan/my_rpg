/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** set_text.c
*/

#include "my.h"
#include "gui.h"
#include "shorting_defines.h"
#include "xml_parser.h"
#include "file.h"
#include "sfml_tools.h"

static int choose_text(char const *line, gui_t *scene_list, int scene_nb)
{
    size_t index = 0;
    char *name_text = cpy_var_name("name=", line);

    if (!name_text)
        return -1;
    for (; scene_list->scenes[scene_nb]->texts[index]; index++) {
        if (my_strcmp(name_text, SCL_T[index]->name)) {
            free(name_text);
            return index;
        }
    }
    free(name_text);
    return -1;
}

static void set_delay_text(char const *line, text_t *text)
{
    text->letter_delay = cpy_var_float(" letter_delay=", line);
    text->appear_delay = cpy_var_float(" appear_delay=", line);
    text->disappear_delay = cpy_var_float(" disappear_delay=", line);
    if (text->letter_delay || text->appear_delay) {
        text->timed = true;
    } else {
        text->timed = false;
    }
}

static void set_color_text(char const *line, text_t *text)
{
    char *color_str = cpy_var_name(" text_color=", line);
    sfColor color = sfWhite;

    if (color_str) {
        color = get_color_from_str(color_str);
        sfText_setColor(text->text_sfml, color);
        free_char_to_null(color_str);
    }
}

text_t *set_any_text(char const *line, text_t *text)
{
    sfVector2f pos = get_coordinates(line);
    int size = cpy_var_int(" size=", line);
    char *font = NULL;

    if (!text)
        return NULL;
    font = cpy_var_name(" font=", line);
    text->string = cpy_var_name(" text=", line);
    replace_char_in_str(text->string, '@', '\n');
    set_delay_text(line, text);
    if (!text->letter_delay)
        text->text_sfml = create_text(NULL, text->string, font, size);
    else
        text->text_sfml = create_text(NULL, NULL, font, size);
    sfText_setPosition(text->text_sfml, pos);
    font = free_char_to_null(font);
    set_color_text(line, text);
    return text;
}

void set_text(char const *line, gui_t *scene_list, size_t scene_nb,
N_U sfRenderWindow *window)
{
    int idx = choose_text(line, scene_list, scene_nb);

    SCL_T[idx] = set_any_text(line, SCL_T[idx]);
}
