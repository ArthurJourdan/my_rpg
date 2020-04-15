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

SRC     =	is_file_openable.c				\
			get_entire_file.c				\
			get_pos_word_in_str.c			\
			get_pos_word_in_double_arr.c	\
			file_len.c						\
			dir_index.c						\
			dir_infos.c						\
			rm_char_in_str.c				\
			check_comments.c				\

OBJ     =       $(SRC:.c=.o)

NAME    =       libfile.a

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
		@gcc -g -c -o $@ $^ $(CFLAGS) && $(ECHO) -n $(BOLD) $(GREEN)"  [OK] "$(WHITE) || $(ECHO) -n $(BOLD) $(RED)"  [KO] "$(WHITE) && $(ECHO) $(BOLD) $< | rev | cut -d'/' -f 1 | rev
