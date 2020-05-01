/*
** EPITECH PROJECT, 2020
** rpg anim
** File description:
** anim data for sprites loading
*/

/**************************************/

typedef struct anim_data {
    char *spritesheet;
    int anim_count;
    int *anim_frames;
    sfVector2i unit_size;
}anim_t;

/**************************************/

#define SPRSH animd->sprsh
#define AC animd->anim_count
#define AF animd->anim_frames
#define ASIZE animd->unit_size

/**************************************/
