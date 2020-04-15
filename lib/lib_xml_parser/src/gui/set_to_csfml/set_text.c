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
    char *name_text = NULL;

    for (; scene_list->scenes[scene_nb]->text[index]; index++) {
        if (name_text) {
            name_text = free_char_to_null(name_text);
        }
        name_text = cpy_var_name("name=", line);
        if (my_strcmp(name_text, sfText_getString(SCL_T[index]))) {
            free(name_text);
            return index;
        }
    }
    return -1;
}

void set_text(char const *line, gui_t *scene_list, size_t scene_nb,
N_U sfRenderWindow *window)
{
    int txt_index = choose_text(line, scene_list, scene_nb);
    sfVector2f pos = get_coordinates(line);
    int size = cpy_var_int(" size=", line);
    char *font = cpy_var_name(" font=", line);
    char *name = (char *)sfText_getString(SCL_T[txt_index]);

    SCL_T[txt_index] = create_text(SCL_T[txt_index], name, font, size);
    sfText_setPosition(scene_list->scenes[scene_nb]->text[txt_index], pos);
    if (font)
        free(font);
}
