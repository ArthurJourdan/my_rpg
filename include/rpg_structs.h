/*
** EPITECH PROJECT, 2020
** structs
** File description:
**
*/

#ifndef RPG_STRUCTS_H
#define RPG_STRUCTS_H

#include <SFML/Graphics.h>
#include <stdbool.h>

/**************************************/
/*************** ENUMS ****************/
/**************************************/

enum side_e {ally, enemy};
enum maze_e {UP, LEFT, DOWN, RIGHT};
enum stype_e {targeted, range, status};
enum scategory_e {blast, instant, sequence}; //un spell blast serait un spell qui ne s'active que quand il touche l'ennemis, un spell instan s'activerai instant (genre un lance-flamme) , un sequence serait un spell plus élaboré avec plusieurs étape (genre une onde de choque qui se propage lentement ou jsp)

/**************************************/
/*************** DICTS ****************/
/**************************************/

//ceci serait les donnée loadé depuis les fichier, les "dictionnaire".

struct game;

typedef struct spell_hitboxes {
    sfIntRect *hitboxes;
    int lingering_time;
    int activation_delay;
}sphit_t;

typedef struct spell_dict {
    int id;
    enum stype_e stype;
    enum scategory_e category;
    int base_damage;
    int mp_cost;
    int cooldown;
    int activation_radius;
    float range;
    float travel_speed;
    sphit_t **hitboxes;
}sp_dict_t;

typedef struct enemy_dict {
    int id;
    int damage;
    int *spell_list;
    int move_speed;
    //behaviour_t behaviour; <-- faudrait trouver un moyen de scripter les mob via des struct (aucune idée de comment pour l'instant)
}e_dict_t;

typedef struct dict {
    sp_dict_t **spell_dict;
    e_dict_t **enemy_dict;
}dict_t;

/**************************************/
/*************** OBJs *****************/
/**************************************/

typedef struct spell_obj {
    bool obj_status;
    int id;
    int frame;
    enum side_e side;
    enum stype_e type;
    enum scategory_e category;
    int activation_radius;
    sphit_t **sphit;
    sfVector2f starting_pos;
    sfVector2f speed;
    sfVector2f pos;
    float range;
}s_obj_t;

typedef struct enemy_obj {
    bool obj_status;
    int id;
    int frame;
    int max_hp;
    int hp;
    int damage;
    int *spell_nodes;
    sfVector2f speed;
    sfVector2f pos;
    sfIntRect *collider;
}e_obj_t;

typedef struct obj {
    e_obj_t e_obj[64];
    s_obj_t s_obj[64];
}obj_t;

/**************************************/
/************** OTHERS ****************/
/**************************************/

typedef struct sprites {
    sfSprite ****enemies;
    sfSprite ***player;
    sfSprite **maps;
}spr_t;

typedef struct spell_node {
    sfKeyCode key;
    sfTime last_activation;
    int spell_id;
    void (*spell_fptr)(struct game *game);
}spn_t;

typedef struct anim_data {
    char *spritesheet;
    int anim_count;
    int *anim_frames;
    sfVector2i unit_size;
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
    int status; //utiliser un mask pour les effets de status
    spn_t **spell_nodes; //les spells débloqué/équipé
    float max_speed;
    float speed;
    float hitbox;
    bool idle;
    sfSprite ***ss;
    dash_t dash;
    sfVector2f collider;
    sfVector2f pos;
    sfSprite *sprite;
    controls_t controls;
    sfTime time;
    int frame;
    sfClock *clock;
}player_t;

typedef struct maze {
    sfSprite *lay1;
    sfSprite *lay2;
    sfImage *coll;
    bool is_open;
    bool is_enemies;
}maze_map_t;

typedef struct layers {
    char ***maps;
    char **dante_maps;
    maze_map_t **maze_maps;
    sfVector2i pos;
}layers_t;

typedef struct game {
    sfEvent event;
    player_t player;
    obj_t *obj;
    layers_t layers;
    int width;
    int height;
    int maze_size;
}game_t;

/**************************************/

#endif
