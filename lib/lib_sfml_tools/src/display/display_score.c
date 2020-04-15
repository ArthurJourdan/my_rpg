/*
** EPITECH PROJECT, 2020
** MUL_game
** File description:
** display_score.c
*/

#include "gui.h"
#include "tools.h"
#include "file.h"
#include "print.h"

static const int SPACE = 30;
static const char *FILE_SCORE = "assets/file_score.txt";

static sfText *set_score_font(sfText *score_in_letters)
{
    sfText *text = sfText_create();
    sfVector2f pos = sfText_getPosition(score_in_letters);

    text = sfText_copy(score_in_letters);
    pos.y += SPACE;
    sfText_setPosition(text, pos);
    return text;
}

char *get_score_from_file(void)
{
    FILE *fd = NULL;
    char *buffer = NULL;
    size_t zero = 0;
    int bigger = 0;

    if (!is_file_fopenable(FILE_SCORE))
        return NULL;
    fd = fopen(FILE_SCORE, "r");
    while (getline(&buffer, &zero, fd) != -1) {
        if (my_getnbr(buffer) > bigger)
            bigger = my_getnbr(buffer);
    }
    fclose(fd);
    return my_reg_nbr(bigger);
}

void display_score(sfRenderWindow *window, sfText **texts,
game_object_t **towers, int index_scene)
{
    char *score_text = NULL;
    static sfText *text = NULL;
    int button_index = get_score_in_text(texts, index_scene);

    if (index_scene == GAME) {
        score_text = count_score(towers, false);
        while (!my_strcmp(sfText_getString(texts[button_index]), "score"))
            button_index++;
    } else if (index_scene == HOME) {
        score_text = get_score_from_file();
        while (!my_strcmp(sfText_getString(texts[button_index]), "Best score"))
            button_index++;
    }
    if (score_text) {
        if (texts[button_index]) {
            text = set_score_font(texts[button_index]);
            sfText_setString(text, score_text);
            sfRenderWindow_drawText(window, text, NULL);
        }
        free(score_text);
    }
}
