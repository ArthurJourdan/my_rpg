/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** shorting_definess.h
*/

#ifndef SHORTING_DEFINES_H
#define SHORTING_DEFINES_H

#define GSC global->scene_list
#define GW global->window
#define FPS global->fps
#define GS global->scene_list
#define GM global->maps

//game
#define GG global->game
#define GGW global->game.width
#define GGH global->game.height
#define GGP global->game.player
#define GGPC global->game.player.controls
#define GGPD global->game.player.dash
#define GGPT global->game.player.time
#define GGL global->game.layers
#define GGLM global->game.layers.maze
#define GGLMM global->game.layers.maze_maps
#define GGLDM global->game.layers.dante_maps
#define GGLP global->game.layers.pos
#define GGS global->game.spell_dict
#define GGO global->game.obj

//player
#define GGPIS global->game.player.p_invent->spell_nodes

//OBJ
#define CO collider->left
#define CT collider->top
#define GGOSG global->game.obj->sp_obj_g

#define ACT global->scene_list->index
#define SC_A global->scene_list->scenes[global->scene_list->index]
#define SC_B global->scene_list->scenes[global->scene_list->index]->buttons
#define SC_I global->scene_list->scenes[global->scene_list->index]->images
#define SC_T global->scene_list->scenes[global->scene_list->index]->texts
#define SC_S global->scene_list->scenes[global->scene_list->index]->sound

#define SL scene_list->scenes
#define ACT_S scene_list->index

// INIT
#define SCL_O sc_list->scenes[sc_nb]
#define SCL_NB scene_list->scenes[scene_nb]
#define SCL_B scene_list->scenes[scene_nb]->buttons
#define SCL_I scene_list->scenes[scene_nb]->images
#define SCL_T scene_list->scenes[scene_nb]->texts

//animd
#define SPRSH animd->spritesheet
#define AC animd->anim_count
#define AF animd->anim_frames
#define ASIZE animd->unit_size

#endif /* !SHORTING_DEFINES_H */
