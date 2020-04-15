/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** init_object_list.c
*/

#include "my.h"
#include "gui.h"
#include "shorting_defines.h"
#include "xml_parser.h"
#include "file.h"
#include "print.h"

static game_object_t *init_one_object(game_object_t *obj)
{
    obj->id = 0;
    obj->name = NULL;
    obj->sprite = NULL;
    obj->speed = 0;
    obj->sound = NULL;
    obj->size_tot_image = 0;
    obj->nb_animation = 0;
    obj->animation_act = 0;
    obj->damage = 0;
    obj->life = 0;
    obj->died = false;
    obj->this_cl = NULL;
    obj->next = NULL;
    obj->explosion = NULL;
    return obj;
}

static game_object_t **malloc_objects(size_t nb_objects)
{
    game_object_t **objects = NULL;

    objects = malloc(sizeof(game_object_t *) * (nb_objects + 1));
    if (!objects)
        return NULL;
    for (size_t a = 0; a < nb_objects; a++) {
        objects[a] = malloc(sizeof(game_object_t));
        if (!objects[a])
            return NULL;
        objects[a] = init_one_object(objects[a]);
        objects[a]->sprite = sfSprite_create();
        objects[a]->this_cl = sfClock_create();
        objects[a]->explosion = malloc(sizeof(game_object_t));
        objects[a]->explosion = init_one_object(objects[a]->explosion);
    }
    objects[nb_objects] = NULL;
    return objects;
}

static game_object_t **assign_names(game_object_t **objects, char const **file,
char const *object_type, char *name_scene)
{
    size_t nb_objects = 0;
    size_t line = get_to_scene(file, name_scene);
    size_t end = get_end_scene(file, name_scene);

    if (line == (size_t)-1)
        return 0;
    for (; line < end; line++) {
        if (get_pos_word_in_str("Game_object", file[line]) != -1 &&
            cmp_var_name(file[line], "id=", object_type)) {
            objects[nb_objects++]->name = cpy_var_name("name=", file[line]);
        }
    }
    return objects;
}

static size_t count_objects(char const **file, char const *object_type,
char *name_scene)
{
    size_t nb_objects = 0;
    size_t line = get_to_scene(file, name_scene);
    size_t end = get_end_scene(file, name_scene);

    if (line == (size_t)-1)
        return 0;
    for (; line < end; line++) {
        if (get_pos_word_in_str("Game_object", file[line]) != -1 &&
            cmp_var_name(file[line], "id=", object_type)) {
            nb_objects++;
        }
    }
    return nb_objects;
}

game_object_t **init_object_list(char const **file, char const *object_type,
char *scene_name)
{
    game_object_t **objects = NULL;
    size_t nb_objects = count_objects(file, object_type, scene_name);

    if (!nb_objects)
        return NULL;
    objects = malloc_objects(nb_objects);
    if (!objects)
        return NULL;
    objects = assign_names(objects, file, object_type, scene_name);
    return objects;
}
