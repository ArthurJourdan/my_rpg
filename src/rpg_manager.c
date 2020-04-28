/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** rpg_manager.c
*/

#include "my_rpg.h"
#include "sfml_tools.h"

#include "events.h"
#include "display.h"

static void display_everything(global_t *global)
{
    static float frame_nb = 0;

    frame_nb++;
    display_images(GW, SC_I);
    display_buttons(global);
    display_texts_struct(global, frame_nb);
    sfRenderWindow_display(GW);
    sfRenderWindow_clear(GW, sfBlack);
}

static void gameplay(global_t *global)
{
    player_movements(global);
}

static void rpg_game(global_t *global, sfClock *game_clock)
{
    float nb_sec = sfTime_asSeconds(sfClock_getElapsedTime(game_clock));
    float nb_fram = nb_sec * FPS;

    if (nb_fram >= 1.0f) {
        sfClock_restart(game_clock);
        for (float a = 0; a < nb_fram; a++) {
            sfRenderWindow_pollEvent(GW, &GG.event);
            event_management(global);
            if (ACT == GAME) {
                gameplay(global);
                display_player(GW, global);
            }
            display_everything(global);
            // if (GS[ACT]->to_do)
            // GS[ACT]->to_do(global);
        }
    }

}

void rpg_manager(global_t *global)
{
    sfClock *game_clock = sfClock_create();

    GS->index = HOME;
    sfRenderWindow_setKeyRepeatEnabled(GW, sfFalse);
    sfRenderWindow_setFramerateLimit(GW, 120);
    while (sfRenderWindow_isOpen(GW)) {
        rpg_game(global, game_clock);
    }
    sfClock_destroy(game_clock);
    destroy_game(global);
}
