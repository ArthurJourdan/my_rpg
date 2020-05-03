/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** set_button.c
*/

#include "my.h"
#include "gui.h"
#include "shorting_defines.h"
#include "xml_parser.h"
#include "file.h"
#include "sfml_tools.h"
#include "button.h"

static actions_t const all_actions[] = {
    {"Useless", NULL},
    {"Quit", &go_out},
    {"Start", &go_start},
    {"Pause", &go_pause},
    {"Resume", &go_back_to_game},
    {"Options", &go_options},
    {"Starting_menu", &go_starting_menu},
    {"Restarting_menu", &go_restart},
    {"Volume_music_up", &volume_music_up},
    {"Volume_music_down", &volume_music_down},
    {"Volume_all_musics_up", &volume_all_musics_up},
    {"Volume_all_musics_down", &volume_all_musics_down},
    {"Volume_sound_up", &volume_sounds_up},
    {"Volume_sound_down", &volume_sounds_down},
    {"Volume_all_sounds_up", &volume_all_sounds_up},
    {"Volume_all_sounds_down", &volume_all_sounds_down},
    {"Increase_fps", &increase_fps},
    {"Decrease_fps", &decrease_fps},
    {"Tutorial", &go_htp}
};

static int choose_button(char const *line, gui_t *scene_list, int scene_nb)
{
    char **button_names = list_button_names(SCL_B);
    int index = -1;

    if (!button_names) {
        return -1;
    }
    index = get_var_index(line, button_names);
    free_double_char_arr(button_names);
    return index;
}

static void set_button_sprite(gui_t *scene_list, char const *line,
int scene_nb, int button_index)
{
    char *info = cpy_var_name(" image=", line);
    size_t info_nb = 0;

    if (is_file_openable(info)) {
        add_texture_rectshape(SCL_B[button_index]->rect, info);
        info = free_char_to_null(info);
        info_nb = cpy_var_int(" nb_animations=", line);
        SCL_B[button_index]->nb_animations = info_nb;
        info_nb = cpy_var_int(" size_total=", line);
        SCL_B[button_index]->size_tot = info_nb;
    } else {
        sfRectangleShape_setFillColor(SCL_B[button_index]->rect, sfTransparent);
    }
}

static void set_button_text(char const *line, gui_t *scene_list,
int scene_nb, int index)
{
    char *button_action = cpy_var_name(" action=", line);

    SCL_B[index]->text = malloc(sizeof(text_t));
    SCL_B[index]->text->name = my_strcpy(SCL_B[index]->name);
    set_any_text(line, SCL_B[index]->text);
    if (!button_action)
        return;
    for (size_t a = 0; a < ARRAY_SIZE(all_actions); a++) {
        if (my_strcmp(button_action, all_actions[a].name_act)) {
            SCL_B[index]->action = all_actions[a].action;
            break;
        }
    }
    free(button_action);
}

static sfRectangleShape *set_rectangle(char const *line)
{
    sfRectangleShape *rect = NULL;
    sfVector2f pos = get_coordinates(line);
    sfVector2f size = {0};

    size = get_dimensions(line);
    rect = create_rectshape(NULL, size);
    set_rectshape_color(rect, sfTransparent, sfWhite, 0.7);
    sfRectangleShape_setPosition(rect, pos);
    return rect;
}

void set_button(char const *line, gui_t *scene_list, size_t scene_nb,
N_U sfRenderWindow *window)
{
    int b_idx = choose_button(line, scene_list, scene_nb);

    if (b_idx == -1 || scene_nb == -1)
        return;
    SCL_B[b_idx]->rect = set_rectangle(line);
    set_color_button(SCL_B[b_idx], (char * const )line);
    set_button_sprite(scene_list, line, scene_nb, b_idx);
    set_button_text(line, scene_list, scene_nb, b_idx);
    SCL_B[b_idx]->sound = set_any_sound(line);
}
