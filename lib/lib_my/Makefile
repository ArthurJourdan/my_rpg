##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makes library
##

ECHO    =       /bin/echo -e
DEFAULT =       "\033[00m"
#SHELL  =       "\e[0;0m"

DEFAULT =       "\e[0m"
BOLD	=       "\e[1m"
DIM	=       "\e[2m"
UNDLN	=       "\e[4m"
SHINE   =       "\e[5;37m"
RODE    =       "\e[9;30m"
IDK   =       "\e[5;37m"

BLACK	=       "\e[30m"
RED	=       "\e[31m"
GREEN	=       "\e[32m"
YELLOW	=       "\e[33m"
BLUE	=       "\e[34m"
MAGENTA	=       "\e[35m"
CYAN	=       "\e[36m"
WHITE	=       "\e[37m"

LIGHT_GREY      =       "\e[90m"
LIGHT_RED       =       "\e[91m"
LIGHT_GREEN     =       "\e[92m"
LIGHT_YELLOW    =       "\e[93m"
LIGHT_BLUE      =       "\e[94m"
LIGHT_MAGENTA   =       "\e[95m"
LIGHT_CYAN      =       "\e[96m"

CFLAGS	=       -I ../../include/

SRC     =	auto_malloc.c			\
		my_strlen.c			\
		my_getnbr.c			\
		my_getdigit.c			\
		my_strcmp.c			\
		my_strcat.c			\
		my_strcat_path.c		\
		my_str_to_word_arr.c		\
		my_double_arr_cpy.c		\
		my_str_is_alphanum.c		\
		my_str_is_nothing.c		\
		error_msg.c			\
		my_strcpy.c			\
		free_double_arr.c		\
		my_getfloat.c			\
		my_reg_nbr.c

OBJ     =       $(SRC:.c=.o)

NAME    =       libmy.a

all:		title $(NAME)

title:
		@$(ECHO) $(BOLD) $(YELLOW) Building $(NAME)$(DEFAULT)

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
		@gcc $(CFLAGS) -c -o $@ $^ && $(ECHO) -n $(BOLD) $(GREEN)"  [OK] "$(WHITE) || $(ECHO) -n $(BOLD) $(RED)"  [KO] "$(WHITE) && $(ECHO) $(BOLD) $< | rev | cut -d'/' -f 1 | rev
