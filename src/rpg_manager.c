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

#include "a_malloc.h"

static void display_game(global_t *global)
{
    display_layer1(GW, global);
    npc_appear(global);
    display_player(GW, global);
    if (GGO) {
        display_spell_obj_ground(global, GGO->obj_index);
        display_spell_obj_txt(global, GGO->sp_obj_g[0].show_text);
    }
    display_layer2(GW, global);
    display_enemy(global);
    display_spell(global);
    display_inventory(global);
}

static void display_everything(global_t *global)
{
    static float frame_nb = 0;

    frame_nb++;
    if (ACT == GAME)
        display_game(global);
    display_images(GW, SC_I);
    display_buttons(global);
    display_texts_struct(global, frame_nb);
    sfRenderWindow_display(GW);
    sfRenderWindow_clear(GW, sfBlack);
}

static void gameplay(global_t *global)
{
    event_management(global);
    check_spell_active(global);
    if (ACT == GAME) {
        player_movements(global);
        enemy_management(global);
        if (GGO && player_colliding_spell(&GG, GGO->obj_index) &&
        GGOSG[GGO->obj_index].active)
            check_spell(global, 0, &GGP);
        player_spells(global);
    }
}

static void rpg_game(global_t *global, sfClock **game_clock)
{
    float nb_sec = sfTime_asSeconds(sfClock_getElapsedTime(*game_clock));
    float nb_fram = nb_sec * FPS;

    if (nb_fram >= 1.0f) {
        sfClock_restart(*game_clock);
        display_everything(global);
        for (float a = 0; a < nb_fram; a++) {
            if (!global->cinematic) {
                sfRenderWindow_pollEvent(GW, &GG.event);
                gameplay(global);
            }
        }
    }
}

void rpg_manager(global_t *global)
{
    sfClock *game_clock = sfClock_create();

    sfRenderWindow_setKeyRepeatEnabled(GW, true);
    sfRenderWindow_setFramerateLimit(GW, FPS);
    change_scene(GS, HOME);
    while (sfRenderWindow_isOpen(GW)) {
        rpg_game(global, &game_clock);
    }
    sfClock_destroy(game_clock);
    a_malloc(A_MALLOC_FREE | A_LIST(2));
    destroy_game(global);
}
