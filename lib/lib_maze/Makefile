##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compile programs
##

ECHO    =       /bin/echo -e
DEFAULT =       "\e[0;00m"
RED     =       "\e[1;31m"
GREEN   =       "\e[1;32m"
TEAL    =       "\e[1;36m"
YELLOW  =       "\e[1;33m"
MAGENTA =       "\e[1;35m"

SRCDIR  =       src/
INCDIR  =       include/

SRC     =       $(SRCDIR)maze_main.c		\
		$(SRCDIR)init_maze.c		\
		$(SRCDIR)backtracking.c		\
		$(SRCDIR)pathfinder.c		\
		$(SRCDIR)tools.c

OBJ     =       $(SRC:.c=.o)

CFLAGS  +=      -Wall -W -g     \
		-I $(INCDIR)

NAME    =       libmaze.a

all:            title $(NAME)

title:
		@$(ECHO) $(MAGENTA)★★★ ♬ ♫ ♪♩   \
		$(RED)Building $(NAME)          \
		$(MAGENTA)♩♪♫ ♬ ★★★$(DEFAULT)

$(NAME):        $(OBJ)
		@ar rc $(NAME) $(OBJ) &&			\
		$(ECHO) $(GREEN)✓$(YELLOW)" BUILD SUCCESS !"    \
		$(GREEN)✓$(DEFAULT) ||                          \
		$(ECHO) $(RED)✗$(YELLOW)" BUILD FAILED !"       \
		$(RED)✗$(DEFAULT)
		mv $(NAME) ../

clean:
		@$(RM) $(OBJ)
		@$(ECHO) $(GREEN)✓" CLEAN "$(NAME)$(DEFAULT)

fclean:         clean
		@$(RM) ../$(NAME)
		@$(ECHO) $(GREEN)✓" FCLEAN "$(NAME)$(DEFAULT)

re:             fclean all

%.o : %.c
		@gcc -c -o $@ $^ $(CFLAGS) &&           \
		$(ECHO) -n $(GREEN)"  [OK] "$(TEAL) ||  \
		$(ECHO) -n $(RED)"  [NO] "$(TEAL) &&    \
		$(ECHO) $< | rev | cut -d'/' -f 1 | rev
