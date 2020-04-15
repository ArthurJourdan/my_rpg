/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** init_image_list.c
*/

#include "my.h"
#include "gui.h"
#include "shorting_defines.h"
#include "xml_parser.h"
#include "file.h"

static sfSprite **malloc_images(size_t nb_images)
{
    sfSprite **images = NULL;

    images = malloc(sizeof(sfSprite *) * (nb_images + 1));
    if (!images)
        return NULL;
    for (size_t a = 0; a < nb_images; a++) {
        images[a] = NULL;
    }
    images[nb_images] = NULL;
    return images;
}

size_t count_images(char const **file, char *name_scene)
{
    size_t nb_images = 0;
    size_t line = get_to_scene(file, name_scene);
    size_t end = get_end_scene(file, name_scene);

    for (; line < end; line++) {
        if (get_pos_word_in_str("Image ", file[line]) != -1) {
            nb_images++;
        }
    }
    return nb_images;
}

sfSprite **init_image_list(char const **file, char *name_scene)
{
    sfSprite **images = NULL;
    size_t nb_images = count_images(file, name_scene);

    if (!nb_images) {
        return NULL;
    }
    images = malloc_images(nb_images);
    if (!images) {
        return NULL;
    }
    return images;
}