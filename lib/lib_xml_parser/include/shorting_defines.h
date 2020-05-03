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
#define GGPXS(a) global->game.pixel[a].speed
#define GGPX(a) global->game.pixel[a].size
#define GGPS(a) global->game.pixel[a].start
#define GGPP(a) global->game.pixel[a].pos
#define GGPE(a) global->game.pixel[a].end
#define GGPR(a) global->game.pixel[a].density
#define GGW global->game.width
#define GGH global->game.height
#define GGF global->game.framebuffer
#define GGTF global->game.texture_fb
#define GGSF global->game.sprite_fb
#define GGM global->game.maze_size
//player
#define GGP global->game.player
#define GGPL global->game.player.look
#define GGPC global->game.player.controls
#define GGPD global->game.player.dash
#define GGPT global->game.player.time
//layers
#define GGL global->game.layers
#define GGLM global->game.layers.maze
#define GGLMM global->game.layers.maze_maps
#define GGLDM global->game.layers.dante_maps
#define GGLP global->game.layers.pos
#define GGS global->game.spell_dict
#define GGEN global->game.ennemy_dict
#define GGO global->game.obj

//player
#define GGPIS global->game.player.p_invent->spell_nodes
#define GGOS(a) global->game.obj->s_obj[a]

//OBJ
#define CO collider->left
#define CT collider->top
#define GGOSG global->game.obj->sp_obj_g

// NPC
#define GGNPC global->game.npc_list
#define NPC_XY global->game.npc_list[npc_idx]->idx_texture
#define NPCX global->game.npc_list[npc_idx]->idx_texture.x
#define NPCY global->game.npc_list[npc_idx]->idx_texture.y
#define NPCS global->game.npc_list[npc_idx]->sprite[NPCX][NPCY]
#define NPCS_ONE global->game.npc_list[npc_idx]->sprite
#define NPC_MAPX global->game.npc_list[npc_idx]->map_pos.x
#define NPC_MAPY global->game.npc_list[npc_idx]->map_pos.y
#define NPC_POS global->game.npc_list[npc_idx]->pos
// !NPC

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
// !INIT

//animd
#define SPRSH animd->spritesheet
#define AC animd->anim_count
#define AF animd->anim_frames
#define ASIZE animd->unit_size

//enemy
#define E_OBJ_STATUS enemy->obj_status
#define E_ID enemy->id
#define E_FRAME enemy->frame
#define E_FACING enemy->facing
#define E_POS enemy->pos
#define E_SPEED enemy->speed
#define E_DMG enemy->damage
#define E_SPELL enemy->spell_nodes
#define E_COLLIDER enemy->collider
#define E_MOVET enemy->movet
#define E_FRAMET enemy->framet
#define E_HP enemy->hp
#define E_MHP enemy->max_hp
#define E_CLOCK global->game.e_clock
#define E_BOX enemy->collider
#define GGOE global->game.e_obj
#define E_DICT global->game.ennemy_dict
#define HEALTHBARSPR global->game.healthbar
#define HEALTHBARPATH "assets_rpg/images/healthbar.png"
#define PHEALTHBARSPR global->game.phealthbar
#define PHEALTHBARPATH "assets_rpg/images/phealthbar.png"

#endif /* !SHORTING_DEFINES_H */
