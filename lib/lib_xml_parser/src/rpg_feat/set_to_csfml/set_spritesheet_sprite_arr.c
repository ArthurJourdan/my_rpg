/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** set_spritesheet_sprite_arr.c
*/

#include "file.h"

#include "xml_parser.h"
#include "rpg_structs.h"
#include "my_rpg.h"

static int *fill_anim_arr(char *tmp_frames)
{
    int *anim_count = NULL;
    size_t nb_lines = 0;
    char **tmp_nb_frames = my_sep_parser(tmp_frames, ",");

    if (!tmp_nb_frames)
        return NULL;
    nb_lines = my_arrlen(tmp_nb_frames);
    anim_count = malloc(sizeof(int) * (nb_lines + 1));
    if (!anim_count)
        return NULL;
    rm_char_in_double_arr(tmp_nb_frames, ' ');
    for (size_t a = 0; tmp_nb_frames[a]; a++) {
        if (my_str_is_num(tmp_nb_frames[a]))
            anim_count[a] = my_getnbr(tmp_nb_frames[a]);
        else
            anim_count[a] = 0;
    }
    anim_count[nb_lines] = -1;
    return anim_count;
}

static int count_anims(animd_t infos_sprite)
{
    int nb_anims = 0;

    if (!infos_sprite.anim_frames)
        return 0;
    for (size_t a = 0; infos_sprite.anim_frames[a] != -1; a++)
        nb_anims++;
    return nb_anims;
}

static animd_t set_infos_sprite(char * const line)
{
    animd_t infos_sprite = {NULL, -1, NULL, {0, 0}};
    char *tmp_frames = NULL;

    infos_sprite.spritesheet = cpy_var_name(" image=", line);
    tmp_frames = cpy_var_name(" anim_size=", line);
    if (tmp_frames) {
        infos_sprite.anim_frames = fill_anim_arr(tmp_frames);
        free(tmp_frames);
    }
    infos_sprite.anim_count = count_anims(infos_sprite);
    infos_sprite.unit_size = get_dimensions(line);
    return infos_sprite;
}

sfSprite ***set_sprite_arr(char * const line)
{
    sfSprite ***sprites = NULL;
    animd_t info = set_infos_sprite(line);

    if (!info.spritesheet || !info.unit_size.x || !info.unit_size.y) {
        return NULL;
    }
    if (!info.anim_count || !info.anim_frames) {
        free(info.spritesheet);
        return NULL;
    }
    if (!is_file_openable(info.spritesheet)) {
        free(info.spritesheet);
        free(info.anim_frames);
        return NULL;
    }
    sprites = spritesheet_load(&info);
    free(info.spritesheet);
    free(info.anim_frames);
    return sprites;
}
