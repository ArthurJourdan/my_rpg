/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** init_text_list
*/

#include "my.h"
#include "gui.h"
#include "shorting_defines.h"
#include "xml_parser.h"
#include "file.h"
#include "text.h"

static text_t *init_one_text(text_t *text)
{
    text->name = NULL;
    text->string = NULL;
    text->text_sfml = NULL;
    text->timed = false;
    text->letter_delay = 0;
    text->appear_delay = 0;
}

static text_t **malloc_text(size_t nb_text)
{
    text_t **texts = NULL;

    texts = malloc(sizeof(text_t *) * (nb_text + 1));
    if (!texts)
        return NULL;
    for (size_t a = 0; a < nb_text; a++) {
        if (!(texts[a] = malloc(sizeof(text_t))))
            return NULL;
        texts[a] = init_one_text(texts[a]);
    }
    texts[nb_text] = NULL;
    return texts;
}

static text_t **assign_names(text_t **texts, char const **file, char *namescene)
{
    int nb_text = 0;
    size_t line = get_to_scene(file, namescene);
    size_t end = get_end_scene(file, namescene);
    char *info = NULL;

    if (line == (size_t)-1)
        return 0;
    for (; line < end; line++) {
        if (get_pos_word_in_str("Text ", file[line]) != -1) {
            info = cpy_var_name(" name=", file[line]);
            if (info) {
                texts[nb_text]->name = my_strcpy(info);
                info = free_char_to_null(info);
            }
            nb_text++;
        }
    }
    return texts;
}

static size_t count_texts(char const **file, char *name_scene)
{
    size_t nb_text = 0;
    size_t line = get_to_scene(file, name_scene);
    size_t end = get_end_scene(file, name_scene);

    if (line == (size_t)-1)
        return 0;
    for (; line < end; line++) {
        if (get_pos_word_in_str("Text ", file[line]) != -1) {
            nb_text++;
        }
    }
    return nb_text;
}

text_t **init_text_list(char const **file, char *name_scene)
{
    text_t **texts = NULL;
    size_t nb_text = count_texts(file, name_scene);

    if (!nb_text) {
        return NULL;
    }
    texts = malloc_text(nb_text);
    if (!texts)
        return NULL;
    texts = assign_names(texts, file, name_scene);
    return texts;
}
