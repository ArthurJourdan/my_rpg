##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makes library
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

CFLAGS	=       -I ../../include/

LIBDIR	=	../lib

SRC     =	my_dprintf.c		\
		my_putstr.c		\
		my_putdouble_arr.c	\
		my_putchar.c		\
		my_putnbr.c		\
		my_puthexa.c		\
		my_puthexa_c.c		\
		my_putoctal.c		\
		my_putbin.c		\
		put_non_p.c

OBJ     =       $(SRC:.c=.o)

NAME    =       libprint.a

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
		@gcc $(CFLAGS) -c -o $@ $^ && $(ECHO) -n $(BOLD) $(GREEN)"  [OK] "$(WHITE) || $(ECHO) -n $(BOLD) $(RED)"  [KO] "$(WHITE) && $(ECHO) $(BOLD) $< | rev | cut -d'/' -f 1 | rev
