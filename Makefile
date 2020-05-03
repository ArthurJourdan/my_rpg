##
## EPITECH PROJECT, 2019
## makefile
## File description:
## lib
##

ECHO    =       /bin/echo -e
DEFAULT =       "\033[00m"
#SHELL  =       "\e[0;0m"

DEFAULT =       "\e[0m"
BOLD    =       "\e[1m"
DIM     =       "\e[2m"
UNDLN   =       "\e[4m"
SHINE   =       "\e[5;37m"
RODE    =       "\e[9;37m"

BLACK   =       "\e[30m"
RED     =       "\e[31m"
GREEN   =       "\e[32m"
YELLOW  =       "\e[33m"
BLUE    =       "\e[34m"
MAGEN   =       "\e[35m"
CYAN    =       "\e[36m"
WHITE   =       "\e[1;37m"

LIGHT_RED       =       "\e[91m"
LIGHT_GREEN     =       "\e[92m"
LIGHT_YELLOW    =       "\e[93m"
LIGHT_BLUE      =       "\e[94m"
LIGHT_MAGEN     =       "\e[95m"
LIGHT_CYAN      =       "\e[96m"

TESTNAME	=	unit_tests

TEST		=   $(TESTNAME) --coverage -lcriterion

INCLUDE		=	-I include

CFLAGS		=	-W -Wall -Wextra $(INCLUDE)

RMFLAGS		=	*.gcda *.gcno src/*.gcda src/*.gcno

LIBDIR		=	./lib/

SRCDIR		=	src/
INITDIR		=	$(SRCDIR)init/
DISPDIR		=	$(SRCDIR)display/
GAMEDIR		=	$(SRCDIR)gameplay/
NPC_ACT		=	$(GAMEDIR)npc_actions/
TOOLDIR		=	$(SRCDIR)tools/

INIT		=	$(INITDIR)init_controls.c	\
			$(INITDIR)init_game.c		\
			$(INITDIR)init_player.c		\
			$(INITDIR)init_layers.c		\
			$(INITDIR)init_maze_maps.c

TOOLS		=	$(TOOLDIR)colorcmp.c	\
			$(TOOLDIR)image_cmp.c	\
			$(TOOLDIR)make_it_rain.c\
			$(TOOLDIR)swap_map.c	\
			$(TOOLDIR)my_goto.c

GAME		=	$(GAMEDIR)player_movement.c	\
			$(GAMEDIR)line_movement.c	\
			$(GAMEDIR)diag_movement.c	\
			$(GAMEDIR)player_key_pressed.c	\
				$(GAMEDIR)npc_appear.c

NPC			=	$(NPC_ACT)npc_discuss.c	\
				$(NPC_ACT)npc_zoom.c

DISP		=	$(DISPDIR)display_player.c	\
				$(DISPDIR)display_npc.c	\

BUTTON		=	$(SRCDIR)button_actions/

EVENT		=	$(SRCDIR)events/

DESTROY		=	$(SRCDIR)destroy/

OPTION		=	$(SRCDIR)options/

DISPLAY		=	$(SRCDIR)display/

PLAYER		=	$(SRCDIR)player/

PLAYER_INV	=	$(PLAYER)inventory/

SPELL		=	$(SRCDIR)spells/

ENEMYDIR	=	$(SRCDIR)enemy_management/

SRC		=	${SRCDIR}main.c	\
			$(INIT)		\
			$(DISP)		\
			$(TOOLS)	\
			$(GAME)		\
			$(NPC)		\
					\
			${SRCDIR}rpg_manager.c		\
							\
			$(BUTTON)change_scene.c		\
			$(BUTTON)go_start.c		\
			$(BUTTON)go_pause.c		\
			$(BUTTON)go_out.c		\
			$(BUTTON)go_options.c		\
			$(BUTTON)go_htp.c		\
			$(BUTTON)go_starting_menu.c	\
			$(BUTTON)go_back_to_game.c	\
			$(BUTTON)music_volume.c	\
			$(BUTTON)volume_sound.c	\
			$(BUTTON)change_fps.c	\
			\
			$(EVENT)event_management.c	\
			$(EVENT)button_management.c	\
			$(EVENT)stopping_events.c	\
							\
			$(OPTION)change_sounds_volume.c	\
			$(OPTION)change_music_volume.c	\
							\
			$(PLAYER)check_collision.c		\
			$(PLAYER)player_spells.c		\
			$(PLAYER_INV)add_spell.c		\
			$(PLAYER_INV)check_inventory.c	\
			$(PLAYER_INV)display_inventory.c	\
			$(PLAYER_INV)draw_inventory.c		\
			$(PLAYER_INV)init_inventory.c		\
			$(PLAYER_INV)show_pickup_text.c		\
							\
			$(SPELL)display_spell_obj.c				\
			$(SPELL)init_spell_obj_ground.c			\
			$(SPELL)spell_fct.c						\
			$(SPELL)init_spell_obj.c				\
			$(SPELL)check_activation.c				\
							\
			$(DISPLAY)display_text_struct.c	\
			$(DISPLAY)display_button.c	\
			$(DISPLAY)sprites_load.c	\
			$(DISPLAY)dash_load.c		\
							\
			$(DISPLAY)display_map.c	\
			\
			$(DESTROY)destroy_everything.c	\
			$(DESTROY)pixels_destroy.c	\
			$(DESTROY)player_destroy.c	\
			\
			$(ENEMYDIR)enemy_clear.c	\
			$(ENEMYDIR)enemy_display.c	\
			$(ENEMYDIR)enemy_init.c		\
			$(ENEMYDIR)enemy_management.c	\
			$(ENEMYDIR)enemy_movement.c	\
			$(ENEMYDIR)placeholder_load.c	\
			$(ENEMYDIR)enemy_collision.c	\

OBJ		=       $(SRC:.c=.o)

NAME		=	my_rpg

SRC_LIB		=	xml_parser	\
			file		\
			print		\
			my		\
			maze		\
			sfml_tools	\
			csfml-graphics	\
			csfml-system	\
			csfml-window	\
			csfml-audio

LIB_PATHS	=       $(LIBDIR)lib_my		\
			$(LIBDIR)lib_print	\
			$(LIBDIR)lib_file	\
			$(LIBDIR)lib_sfml_tools	\
			$(LIBDIR)lib_xml_parser	\
			$(LIBDIR)lib_maze


LIBRARIES       =       $(SRC_LIB:%=-l%)
#LIB_PATHS_FLAG  =       $(LIB_PATHS:%=-L%)

LDFLAGS		=	-L./lib $(LIBRARIES) -lncurses -lm

all:            $(NAME)

title:
		@nm-online -q -t 2 -x || /bin/false \
		&& curl http://artii.herokuapp.com/make?text=$(NAME) --max-time 10 --connect-timeout 5 \
		|| $(ECHO) $(BOLD) $(YELLOW) Building $(NAME)$(DEFAULT)
		@$(ECHO)

lib:
	@$(ECHO)
	@for MAKE_PATH in $(LIB_PATHS) ; do \
		make -C $$MAKE_PATH -s ; \
	done

pre_building:
	@$(ECHO) "\n"$(BOLD) $(CYAN) Building $(NAME) $(DEFAULT)

$(NAME):	lib pre_building $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(LDFLAGS) \
	&& $(ECHO) $(BOLD) $(GREEN)"-> BUILD SUCCESS !"$(DEFAULT) || $(ECHO) $(BOLD) $(RED)"-> BUILD FAILED"$(DEFAULT)

clean:
		@for MAKE_PATH in $(LIB_PATHS) ; do \
			make clean -C $$MAKE_PATH -s ; \
		done
		@rm -f $(OBJ)
		@rm -f $(RMFLAGS)
		@($(ECHO) $(BOLD) $(GREEN)✓" CLEAN "$(NAME)$(DEFAULT))

fclean:
		@for MAKE_PATH in $(LIB_PATHS) ; do \
			make fclean -C $$MAKE_PATH -s ; \
		done
		@rm -f $(OBJ)
		@rm -f $(NAME)
		@rm -f $(RMFLAGS)
		@rm -f $(TESTNAME)
		@($(ECHO) $(BOLD) $(GREEN)✓" FCLEAN "$(NAME)$(DEFAULT))

re:             fclean all

tests_run:
		@$(ECHO)
		@for MAKE_PATH in $(LIB_PATHS) ; do \
			make fclean -C $$MAKE_PATH -s ; \
		done
		@gcc -o $(TEST) \
		${SRCDIR}.c \
		tests/unit_tests.c \
		$(LIB) $(INCLUDE) && $(ECHO) $(BOLD) $(GREEN)"-> BUILD SUCCESS !"$(DEFAULT) || $(ECHO) $(BOLD) $(RED)"-> BUILD FAILED"$(DEFAULT)
		@$(ECHO)
		./$(TESTNAME)

debug:		CFLAGS += -g
debug:		re

%.o :		%.c
		@gcc -c -o $@ $^ $(CFLAGS) && $(ECHO) -n $(BOLD) $(GREEN)"  [OK] "$(WHITE) || $(ECHO) -n $(BOLD) $(RED)"  [KO] "$(WHITE) && $(ECHO) $(BOLD) $< | rev | cut -d'/' --fields 1 | rev

.PHONY:		all title clean fclean re tests_run debug lib pre_building
