/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** xml_parser.h
*/

#ifndef XML_PARSER_H_
#define XML_PARSER_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "time.h"

#include "my.h"

#include "global.h"
#include "gui.h"
#include "text.h"
#include "shorting_defines.h"

#include "rpg_structs.h"
#include "npc.h"

typedef struct {
    char *type;
    void (*ptr)(char const *, gui_t *, size_t, sfRenderWindow *);
} gui_functions_t;

typedef struct paths {
    char *gui;
    char *maps;
    char *game;
} filepaths_t;

global_t *xml_parser(char const *global_filepath);

game_t fill_in_data_game(char * const filepath, global_t *global);

char **check_get_xml_file(char const *filepath);
// NORM
bool is_it_xml(char const **file);

bool are_quotes_filled(char const *line, int check, int nb_line);
bool are_wards_good(char const *line, int check, int nb_line);
bool are_equals_filled(char const *line, N_U int check, int nb_line);
bool is_statement_quotation(char const *line, int check, int nb_line);

bool xml_error_msg(char c, int nb_line, int pos);

bool are_wards_closed(char const **file);
// ! NORM

void get_scene_name(char const *line, char *scene_name);

// GUI

//MEMORY ALLOCATION
gui_t *malloc_all_structs(char const **file);

bool init_scene_list(char const **file, gui_t *scene_list);
button_t **init_button_list(char const **file, char *name_scene);
text_t **init_text_list(char const **file, char *name_scene);
sfSprite **init_image_list(char const **file, char *name_scene);
sfRectangleShape *init_game_board(void);

// RPG_FEAT
game_t init_game_null(void);
game_t malloc_all_game_structs(char **file, game_t game);

sp_dict_t **init_spell_dict(char **file);
e_dict_t **init_ennemy_dict(char **file);
npc_t **init_npc_list(char **file);
// ! RPG_FEAT

// ! MEMORY ALLOCATION

//SET TO SFML
void fill_in_gui_struct(char const **file, gui_t *scene_list,
sfRenderWindow *window);

sfClock *create_clock(void);

void set_text(char const *line, gui_t *scene_list, size_t scene_nb,
sfRenderWindow *window);
void set_image(char const *line, gui_t *scene_list, size_t scene_nb,
sfRenderWindow *window);
void set_button(char const *line, gui_t *scene_list, size_t scene_nb,
sfRenderWindow *window);
void set_color_button(button_t *button, char *const line);
void set_music(char const *line, gui_t *scene_list, size_t scene_nb,
sfRenderWindow *window);
void set_sound(char const *line, gui_t *scene_list, size_t scene_nb,
sfRenderWindow *window);
sfSound *set_any_sound(char const *line);

// RPG FEAT
global_t *init_global_vars(char const global_fp[], global_t *global_struct);
sfRenderWindow *init_window(char const **file);

// ! GUI

game_t set_game_structs(char **file, game_t game, global_t *global);

void set_spell_dict(char **file, sp_dict_t **spell_dict);
void set_ennemy_dict(char **file, e_dict_t **ennemy_dict);
void set_npc_list(char **file, npc_t **npc_dict);

sfSprite ***set_sprite_arr(char * const line);

// ! RPG FEAT

// ! SET TO SFML

// TOOLS


// VAR INTERACTIONS
filepaths_t *get_filepaths_xml(const char *global_file_filepath);

bool cmp_var_name(char const *line, char const *var, char const *name);
char *cpy_var_name(char const *var_name, char const *line);
int cpy_var_int(char var_name[], char const *line);
float cpy_var_float(char var_name[], char const *line);
bool cpy_var_bool(char var_name[], char const *line);

char *cpy_var_name_double_arr(char ward[], char var_name[], char *file[]);
int cpy_var_int_double_arr(char ward[], char var_name[], char *file[]);

sfVector2f get_coordinates(char const *line);
sfVector2f get_dimensions(char const *line);
sfVector2f get_scale(char const *line);

size_t count_images(char const **file, char *name_scene);

char **list_button_names(button_t **buttons);
// ! VAR INTERACTIONS

size_t get_to_scene(char const **file, char *name_scene);
size_t get_end_scene(char const **file, char *name_scene);

size_t scene_chooser(gui_t *scene_list, char const *which_scene);

int get_var_index(char const *line, char **list_names);

// ! TOOLS

// FREE
void free_xml_filepaths(filepaths_t *xml_filepaths);
// !FREE

#endif /* XML_PARSER_H_ */
