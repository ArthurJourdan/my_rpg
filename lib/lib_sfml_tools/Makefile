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

CFLAGS	+=       -I../../include

SRCDIR	=		src/

INIT	=		$(SRCDIR)init/

PXL	=		$(SRCDIR)pixels/

SET		=		$(SRCDIR)set/

GET		=		$(SRCDIR)get/

DISP	=		$(SRCDIR)display/

ADD		=		$(SRCDIR)add/

SRC     =		$(INIT)create_image.c					\
				$(INIT)create_rectangle_shape.c			\
				$(INIT)create_text.c					\
				$(INIT)create_audio.c					\
				$(INIT)create_window.c					\
				\
				$(SET)set_color.c						\
				$(SET)set_image_fullscreen.c			\
				$(SET)set_audio.c						\
				$(SET)set_texture_rect_shape.c			\
				\
				$(GET)mouse_events.c					\
				$(GET)get_color_from_str.c				\
				\
				$(ADD)add_texture.c						\
				\
				$(DISP)display_sprite.c					\
				$(DISP)display_text.c					\
				\
				$(PXL)pixel_form.c					\

OBJ     =       $(SRC:.c=.o)

NAME    =       libsfml_tools.a

all:		 $(NAME) title

title:
		@$(ECHO) $(BOLD) $(YELLOW) Built $(NAME)$(DEFAULT)

$(NAME):        $(OBJ)
		@ar rc $(NAME) $(OBJ)
		mv $(NAME) ../
clean:
		@rm -f $(OBJ)
		@($(ECHO) $(BOLD) $(GREEN)✓" CLEAN "$(NAME)$(DEFAULT))

fclean:
		@rm -f $(OBJ)
		@rm -f ../$(NAME)
		@($(ECHO) $(BOLD) $(GREEN)✓" FCLEAN "$(NAME)$(DEFAULT))

re:		fclean all

%.o :           %.c
		@gcc -c -o $@ $^ $(CFLAGS) && $(ECHO) -n $(BOLD) $(GREEN)"  [OK] "$(WHITE) || $(ECHO) -n $(BOLD) $(RED)"  [KO] "$(WHITE) && $(ECHO) $(BOLD) $< | rev | cut -d'/' -f 1 | rev
