/*
** EPITECH PROJECT, 2020
** player_destroy.c
** File description:
** destroy player_t
*/

#include "my_rpg.h"
#include "shorting_defines.h"

static void game_destroy(global_t *global)
{
    free(GG.obj);
    sfTexture_destroy(GGTF);
    sfSprite_destroy(GGSF);
    sfSprite_destroy(HEALTHBARSPR);
    sfSprite_destroy(PHEALTHBARSPR);
}

static void layers_destroy(global_t *global)
{
    for (int i = 0; GGLDM[i]; i++)
        for (int j = 0; GGLDM[i][j]; j++) {
            sfSprite_destroy(GGLMM[i][j].lay1);
            sfSprite_destroy(GGLMM[i][j].lay2);
            sfImage_destroy(GGLMM[i][j].coll);
        }
    for (int i = 0; i != GGM; i++) {
        free(GGLDM[i]);
        free(GGLMM[i]);
    }
    free(GGLDM);
    free(GGLMM);
    for (int i = 0; i != 4; i++)
        sfSprite_destroy(GGL.wall[i]);
    free(GGL.wall);
}

void player_destroy(global_t *global)
{
    sfClock_destroy(GGPD.clock);
    sfClock_destroy(GGPC.dash_clock);
    sfClock_destroy(GGPC.clock);
    sfClock_destroy(GGP.clock);
    free(GGP.collider);
    sfSprite_destroy(GGP.sprite);
    game_destroy(global);
    layers_destroy(global);
}
