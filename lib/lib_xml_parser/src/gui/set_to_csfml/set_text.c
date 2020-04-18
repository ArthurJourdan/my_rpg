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

void set_delay_text(char const *line, gui_t *scene_list, size_t scene_nb,
int txt_index)
{
    SCL_T[txt_index]->letter_delay = cpy_var_float(" letter_delay=", line);
    SCL_T[txt_index]->appear_delay = cpy_var_float(" appear_delay=", line);
    if (SCL_T[txt_index]->letter_delay || SCL_T[txt_index]->appear_delay) {
        SCL_T[txt_index]->timed = true;
    }
}

void set_text(char const *line, gui_t *scene_list, size_t scene_nb,
N_U sfRenderWindow *window)
{
    int idx = choose_text(line, scene_list, scene_nb);
    sfVector2f pos = get_coordinates(line);
    int size = cpy_var_int(" size=", line);
    char *font = cpy_var_name(" font=", line);

    SCL_T[idx]->string = cpy_var_name(" text=", line);
    SCL_T[idx]->text_sfml = sfText_create();
    set_delay_text(line, scene_list, scene_nb, idx);
    if (!SCL_T[idx]->letter_delay)
        SCL_T[idx]->text_sfml = create_text(SCL_T[idx]->text_sfml,
        SCL_T[idx]->string, font, size);
    else
        SCL_T[idx]->text_sfml = create_text(SCL_T[idx]->text_sfml,
        NULL, font, size);
    sfText_setPosition(SCL_T[idx]->text_sfml, pos);
    if (font)
        free(font);
}
