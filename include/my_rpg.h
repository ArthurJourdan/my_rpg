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

#define vec2f(x, y) (sfVector2f){(x), (y)}
#define msec(x) (x).microseconds / 1000
#define rect_topleft(rect) ((sfVector2f){rect.left, rect.top})
#define rect_topright(rect) ((sfVector2f){rect.left + rect.width, rect.top})
#define rect_botleft(rect) ((sfVector2f){rect.left, rect.top + rect.height})
#define rect_botright(r) ((sfVector2f){r.left + r.width, r.top + r.height})

#define rect(l, t, w, h) (sfIntRect){l, t, w, h}
#define OBJ_SIZE 80
/*MAIN*/
void rpg_manager(global_t *global);
void maze_main(int maze_size, char ***maze);

/*INIT*/
void init_game(global_t *global);
void init_player(global_t *global);
void init_layers(global_t *global);
void put_sprite(global_t *global, char *filepath);
void init_controls(global_t *global);
void init_maze_map(global_t *global);
sfSprite *sprite_create_from_file(char *path);
e_dict_t *placeholder_load(void);

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
void player_key_pressed(global_t *global);
void my_putmap(global_t *global, char *layer1, char *layer2, char *coll);

/*TOOLS*/
bool my_colorcmp(sfColor color1, sfColor color2);
void move_check(sfVector2f next, global_t *global);
void swap_map(sfVector2f next, global_t *global);
void player_dash(sfVector2f next, global_t *global, sfColor dash_color);
sfVector2f my_goto(sfVector2f *pos, sfVector2f start,
sfVector2f target, float speed);
sfColor get_pixel_color(sfVector2f next, global_t *global);

/*PIXELS*/
fbuffer_t *framebuffer_create(unsigned int width, unsigned int heght);
void make_it_rain(global_t *global);
void make_it_snow(global_t *global);

/*DESTROY*/
void pixels_destroy(global_t *global);
void player_destroy(global_t *global);

/*OBJ*/
void init_spell_obj_g(global_t *global);
void display_spell_obj_ground(global_t *global, int pos);
int player_colliding_spell(game_t *game, int pos);
void display_spell_obj_txt(global_t *global, int text);
void display_spell(global_t *global);

/*SPELL*/
void check_spell(global_t *global, int spell_id, player_t *player);
void check_spell_active(global_t *global);
void init_spell_obj(global_t *global);
void targeted_spell(game_t *game, int index);
void player_spells(global_t *global);

/*ENEMY*/
void enemy_management(global_t *global);
void enemy_clear(e_obj_t *enemy);
void enemy_tab_clear(global_t *global);
void display_enemy(global_t *global);
void enemy_zombie_ai(global_t *global, e_obj_t *enemy);
void enemy_tab_init(global_t *global);
void enemy_init(global_t *global, int id, sfVector2f pos);
void check_enemy_collision(global_t *global, e_obj_t *enemy);
void enemy_generate_hord(global_t *global);
int rect_collide_check(sfIntRect rect1, sfIntRect rect2);

#endif /* !MY_RPG_H */
