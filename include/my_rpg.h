/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** my_rpg.h
*/

#ifndef MY_RPG_H
#define MY_RPG_H

#include "global.h"
#include "rpg_structs.h"
#include "maze.h"
#include "player.h"


#define ABS(a) ((a > 0) ? a : (-a))
#define SIGN(a) ((!a) ? 0 : ABS(a) / a)

#define rect(l, t, w, h) (sfIntRect){l, t, w, h}
#define OBJ_SIZE 80
/*MAIN*/
void rpg_manager(global_t *global);
char **maze_main(int maze_size);

/*INIT*/
void init_game(global_t *global);
void init_player(global_t *global);
void init_layers(global_t *global);
void put_sprite(global_t *global, char *filepath);
void init_controls(global_t *global);
void init_maze_map(global_t *global);

/*DISP*/
void display_layer1(sfRenderWindow *win, global_t *global);
void display_layer2(sfRenderWindow *win, global_t *global);
void display_player(sfRenderWindow *win, global_t *global);
sfSprite ***spritesheet_load(animd_t *anim);
sfSprite ***dash_spritesheet_load(animd_t *anim);

/*GAME*/
void line_player_deplacement(global_t *global);
void diag_player_deplacement(global_t *global);
void player_movements(global_t *global);
void my_putmap(global_t *global, char *layer1, char *layer2, char *coll);

/*TOOLS*/
bool my_colorcmp(sfColor color1, sfColor color2);
void move_check(sfVector2f next, global_t *global);
void swap_map(sfVector2f next, global_t *global);
void player_dash(sfVector2f next, global_t *global, sfColor dash_color);

/*OBJ*/
void init_spell_obj(global_t *global);
void display_spell_obj(global_t *global, int pos);
int player_colliding_spell(game_t *game, int pos);
void display_spell_obj_txt(global_t *global, int text);

/*SPELL*/
void check_spell(global_t *global, int spell_id, player_t *player);
#endif /* !MY_RPG_H */
