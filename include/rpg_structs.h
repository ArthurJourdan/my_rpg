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

typedef struct controls {
    int up;
    bool on_up;
    int left;
    bool on_left;
    int down;
    bool on_down;
    int right;
    bool on_right;
    int sprint;
    bool on_sprint;
    int left_spell;
    int right_spell;
    int move_nb;
    sfClock *clock;
}controls_t;

typedef struct player {
    int max_hp;
    int hp;
    int mana;
    int status; //utiliser un mask pour les effets de status
    spn_t **spell_nodes; //les spells débloqué/équipé
    float speed;
    float hitbox;
    sfVector2f collider;
    sfVector2f pos;
    sfSprite *sprite;
    controls_t controls;
}player_t;

typedef struct layers {
    char ***maps;
    sfSprite *layer1;
    sfSprite *layer2;
    sfSprite *coll;
    sfImage *collision;
    int nb;
}layers_t;

typedef struct game {
    sfEvent event;
    player_t player;
    obj_t *obj;
    layers_t layers;
}game_t;

/**************************************/

#endif
