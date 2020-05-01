##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makes linked list library
##

ECHO    =       /bin/echo -e

DEFAULT =       "\e[0m"
BOLD	=       "\e[1m"

BLACK	=       "\e[30m"
RED		=       "\e[31m"
GREEN	=       "\e[32m"
YELLOW	=       "\e[33m"
BLUE	=       "\e[34m"
MAGENTA	=       "\e[35m"
CYAN	=       "\e[36m"
WHITE	=       "\e[37m"

CFLAGS	+=	-I../../include

SRCDIR	=	src/

TOOLS	=	$(SRCDIR)var_interactions/

GUI		=	$(SRCDIR)gui/

RPG		=	$(SRCDIR)rpg_feat/

ALLOC	=	allocate_memory/

SF_SET	=	set_to_csfml/

SRC     =	$(SRCDIR)xml_parser.c								\
			\
			$(SRCDIR)norm_check/xml_norm.c						\
			$(SRCDIR)norm_check/check_norm_line_by_line.c		\
			$(SRCDIR)norm_check/check_get_xml_file.c			\
			\
			$(GUI)$(ALLOC)malloc_all_structs.c					\
			$(GUI)$(ALLOC)init_scene_list.c						\
			$(GUI)$(ALLOC)init_text_list.c						\
			$(GUI)$(ALLOC)init_button_list.c					\
			$(GUI)$(ALLOC)init_image_list.c						\
			\
			$(GUI)$(SF_SET)fill_in_gui_struct.c					\
			\
			$(GUI)$(SF_SET)set_images.c							\
			$(GUI)$(SF_SET)set_button.c							\
			$(GUI)$(SF_SET)set_color_button.c					\
			$(GUI)$(SF_SET)set_music.c							\
			$(GUI)$(SF_SET)set_sound.c							\
			$(GUI)$(SF_SET)set_text.c							\
			\
			$(TOOLS)cpy_var_name.c								\
			$(TOOLS)cpy_var_num.c								\
			$(TOOLS)cmp_var_name.c								\
			$(TOOLS)get_to_scene.c								\
			$(TOOLS)get_coordinates.c							\
			$(TOOLS)get_size.c									\
			$(TOOLS)scene_chooser.c								\
			$(TOOLS)get_var_index.c								\
			$(TOOLS)get_list_names.c							\
			\
			$(TOOLS)get_paths.c									\
			\
			$(RPG)$(SF_SET)init_global_vars.c					\
			$(RPG)$(SF_SET)set_window.c							\
			\
			$(RPG)$(ALLOC)init_maps_list.c						\
			\
			$(RPG)$(SF_SET)set_maps.c							\
			$(RPG)$(SF_SET)order_maps.c							\
			\
			$(RPG)$(ALLOC)malloc_game_structs.c					\
			\
			$(RPG)$(ALLOC)init_spell_dict.c						\
			$(RPG)$(ALLOC)init_ennemy_dict.c					\
			$(RPG)$(ALLOC)init_npc_list.c						\
			\
			$(RPG)$(SF_SET)set_game_structs.c					\
			\
			$(RPG)$(SF_SET)set_spell_dict.c						\
			$(RPG)$(SF_SET)set_ennemy_dict.c					\
			$(RPG)$(SF_SET)set_npc_list.c						\
			\
			$(RPG)$(SF_SET)set_spritesheet_sprite_arr.c			\

OBJ     =	$(SRC:.c=.o)

NAME    =	libxml_parser.a

all:		$(NAME) title

title:
		@$(ECHO) $(BOLD) $(YELLOW) Built $(NAME)$(DEFAULT)

$(NAME):    $(OBJ)
			@ar rc $(NAME) $(OBJ)
			mv $(NAME) ../
clean:
			@rm -f $(OBJ)
			@($(ECHO) $(BOLD) $(GREEN)✓" CLEAN "$(NAME)$(DEFAULT))

fclean:
			@rm -f $(OBJ)
			@rm -f ../$(NAME)
			@($(ECHO) $(BOLD) $(GREEN)✓" FCLEAN "$(NAME)$(DEFAULT))

re:			fclean all

%.o :		%.c
			@gcc -g -c -o $@ $^ $(CFLAGS) && $(ECHO) -n $(BOLD) $(GREEN)"  [OK] "$(WHITE) || $(ECHO) -n $(BOLD) $(RED)"  [KO] "$(WHITE) && $(ECHO) $(BOLD) $< | rev | cut -d'/' -f 1 | rev
