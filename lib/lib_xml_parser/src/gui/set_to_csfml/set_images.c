/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** set_background.c
*/

#include "my.h"
#include "file.h"

#include "gui.h"
#include "shorting_defines.h"
#include "xml_parser.h"
#include "sfml_tools.h"

void set_image(char const *line, gui_t *scene_list, size_t scene_nb,
sfRenderWindow *window)
{
    char *info = cpy_var_name("image=", line);
    sfVector2f pos = get_coordinates(line);
    sfVector2f scale = get_scale(line);
    static size_t index_img = 0;

    if (!info || !is_file_openable(info))
        return;
    SCL_I[index_img] = create_image(NULL, info);
    info = free_char_to_null(info);
    sfSprite_setPosition(SL[scene_nb]->images[index_img], pos);
    if (cpy_var_bool("fullscreen=", line)) {
        set_sprite_fullscreen(window , SL[scene_nb]->images[index_img]);
    } else if (scale.x || scale.y) {
        sfSprite_setScale(SL[scene_nb]->images[index_img], scale);
    }
    if (scene_list->scenes[scene_nb]->images[index_img + 1]) {
        index_img++;
    } else {
        index_img = 0;
    }
}
