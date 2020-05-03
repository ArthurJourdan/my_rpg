/*
** EPITECH PROJECT, 2020
** structs
** File description:
** rpg structs
*/

#ifndef RPG_STRUCTS_H
#define RPG_STRUCTS_H

#include <SFML/Graphics.h>
#include <stdbool.h>

#include "npc.h"

/**************************************/
/*************** ENUMS ****************/
/**************************************/

enum side_e {ally, enemy};
enum maze_e {UP, LEFT, DOWN, RIGHT};
enum stype_e {targeted, range, status, NONE_TYPE = -1};
enum scategory_e {blast, instant, sequence, NONE_CAT = -1};

/**************************************/
/*************** DICTS ****************/
/**************************************/

//ceci serait les donnée loadé depuis les fichier, les "dictionnaire".

struct game;

typedef struct spell_dict {
    int id;
    enum stype_e stype;
    enum scategory_e category;
    int base_damage;
    int activation_radius;
    float range;
    float travel_speed;
    sfSprite *spell_img;
    sfIntRect collider;
}sp_dict_t;

typedef struct enemy_dict {
    int id;
    int damage;
    int life;
    int *spell_list;
    int move_speed;
    sfIntRect hitbox;
    sfSprite ***sprite;
}e_dict_t;

typedef struct dict {
    sp_dict_t **spell_dict;
    e_dict_t **enemy_dict;
}dict_t;

/**************************************/
/*************** OBJs *****************/
/**************************************/

typedef struct spell_obj_ground {
    int id;
    sfSprite *image;
    sfIntRect *collider;
    sfText *pickup_text;
    sfText *replace_text;
    int show_text;
    int active;
} s_obj_g;

typedef struct spell_obj {
    bool obj_status;
    int id;
    int frame;
    enum side_e side;
    enum stype_e type;
    enum scategory_e category;
    int activation_radius;
    sfVector2f starting_pos;
    sfVector2f speed;
    sfVector2f pos;
    sfIntRect *collider;
    sfSprite *img;
    float range;
    int dir;
}s_obj_t;

typedef struct enemy_obj {
    bool obj_status;
    int id;
    int facing;
    int frame;
    int max_hp;
    int hp;
    int damage;
    int *spell_nodes;
    float speed;
    sfTime movet;
    sfTime framet;
    sfVector2f pos;
    sfIntRect collider;
}e_obj_t;

typedef struct obj {
    s_obj_g *sp_obj_g;
    int obj_index;
    e_obj_t e_obj[64];
    s_obj_t *s_obj;
}obj_t;

/**************************************/
/************** OTHERS ****************/
/**************************************/

typedef struct spell_types {
    enum stype_e type;
    void (*spell_fptr)(struct game *, int);
}s_types_t;

typedef struct sprites {
    sfSprite ****enemies;
    sfSprite ***player;
    sfSprite **maps;
}spr_t;

typedef struct spell_node {
    sfKeyCode key;
    sfTime last_activation;
    int spell_id;
    void (*spell_fptr)(struct game *, int);
}spn_t;

typedef struct player_inventory {
    spn_t *spell_nodes;
    int nb_spells;
    sfSprite *invent_bg;
} player_invent_t;

typedef struct anim_data {
    char *spritesheet;
    int anim_count;
    int *anim_frames;
    sfVector2f unit_size;
}animd_t;

typedef struct controls {
    int up;
    bool on_up;
    int left;
    bool on_left;
    int down;
    bool on_down;
    int right;
    bool on_right;
    int dash;
    bool on_dash;
    bool dash_enable;
    int left_spell;
    int right_spell;
    int move_nb;
    sfClock *dash_clock;
    sfClock *clock;
}controls_t;

typedef struct dash {
    sfSprite ***dash;
    int frame;
    sfClock *clock;
    sfVector2f pos;
    float angle;
}dash_t;

typedef struct player {
    int max_hp;
    int hp;
    int mana;
    int status;
    player_invent_t *p_invent;
    float max_speed;
    float speed;
    float hitbox;
    bool idle;
    sfSprite ***ss;
    dash_t dash;
    sfVector2f col_center;
    sfVector2f pos;
    sfSprite *sprite;
    controls_t controls;
    sfTime time;
    int frame;
    sfClock *clock;
    sfIntRect *collider;
    int look;
}player_t;

typedef struct maze {
    sfSprite *lay1;
    sfSprite *lay2;
    sfImage *coll;
    bool is_open;
    bool is_enemies;
    bool spawn;
    int weather;
}maze_map_t;

typedef struct layers {
    sfSprite **wall;
    char **dante_maps;
    maze_map_t **maze_maps;
    sfVector2i pos;
}layers_t;

typedef struct fbuffer{
    unsigned char *pixels;
    unsigned int height;
    unsigned int width;
} fbuffer_t;

typedef struct pixel{
    sfVector2f *start;
    sfVector2f *pos;
    sfVector2f *end;
    float *size;
    float speed;
    int density;
} pixel_t;

typedef struct game {
    sfEvent event;
    pixel_t *pixel;
    fbuffer_t *framebuffer;
    sfTexture *texture_fb;
    sfSprite *sprite_fb;
    sfSprite *healthbar;
    sfSprite *phealthbar;
    player_t player;
    obj_t *obj;
    layers_t layers;
    int width;
    int height;
    int maze_size;
    e_obj_t **e_obj;
    sfClock *e_clock;
    sp_dict_t **spell_dict;
    e_dict_t **ennemy_dict;
    npc_t **npc_list;
}game_t;

/**************************************/

#endif
