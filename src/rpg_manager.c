/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** rpg_manager.c
*/

#include "my_rpg.h"
#include "sfml_tools.h"

#include "events.h"

static void display_everything(global_t *global)
{
    display_images(GW, SC_I);
    display_buttons(GW, SC_B);
    display_texts(GW, SC_T);
    display_player(GW, GGP, GG.layers);
    sfRenderWindow_display(GW);
    sfRenderWindow_clear(GW, sfBlack);
}

static void gameplay(global_t *global)
{
    player_movements(&GGP, &GG.layers);
}

static void rpg_game(global_t *global, sfClock *game_clock)
{
    float nb_sec = sfTime_asSeconds(sfClock_getElapsedTime(game_clock));
    float nb_fram = nb_sec * FPS;

    if (nb_fram >= 1.0f) {
        sfClock_restart(game_clock);
        for (float a = 0; a < nb_fram; a++) {
//            if (ACT == GAME) {
//            }
            gameplay(global);
            display_everything(global);
            sfRenderWindow_pollEvent(GW, &GG.event);
            // if (GS[ACT]->to_do)
            // GS[ACT]->to_do(global);
            event_management(global);
        }
    }

}

void rpg_manager(global_t *global)
{
    sfClock *game_clock = sfClock_create();

    GS->index = HOME;
    sfRenderWindow_setKeyRepeatEnabled(GW, sfFalse);
    while (sfRenderWindow_isOpen(GW)) {
        rpg_game(global, game_clock);
    }
    sfClock_destroy(game_clock);
    destroy_game(global);
}
