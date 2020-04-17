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

typedef struct map_node {
    sfVector2u pos;
    int floor; //si on veux donner du relief sur les map
    int type;
    void (*fptr)(game_t *game); //si on veux trigger qqchse en passant dessus, comme un piege poison, ou ajouter des mob ou jsp
}mapn_t;

typedef struct map_dict {
    int id;
    mapn_t **mapnodes; //ceci serait les détails de chaque "cases" de la map
    sfVector2u size;
    void (*fptr)(game_t *game); //si on veut trigger un boss fight ou qqchse en entrant dans la piece/map
}map_dict_t;

typedef struct dict {
    sp_dict_t **spell_dict;
    e_dict_t **enemy_dict;
    map_dict_t **map_dict;
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
    void (*spell_fptr)(game_t *game);
}spn_t;

typedef struct player {
    int max_hp;
    int hp;
    int status; //utiliser un mask pour les effets de status
    spn_t **spell_nodes; //les spells débloqué/équipé
    sfVector2f speed;
    sfVector2f pos;
}player_t;

typedef struct game {
    player_t *player;
    obj_t *obj;
}game_t;

/**************************************/

#endif
