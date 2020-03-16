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

SRCDIR		=	src/

LIBDIR		=	./lib/

TESTNAME	=	unit_tests

TEST		=       $(TESTNAME) --coverage -lcriterion

INCLUDE		=	-I include

CFLAGS		=	-W -Wall -Werror -Wextra $(INCLUDE)

RMFLAGS		=	*.gcda *.gcno src/*.gcda src/*.gcno

SRC		=	${SRCDIR}main.c				\

OBJ		=       $(SRC:.c=.o)

NAME		=	my_rpg

SRC_LIB		=	file		\
			linked_list	\
			print		\
			my		\

LIB_PATHS	=       $(LIBDIR)lib_my			\
			$(LIBDIR)lib_print		\
			$(LIBDIR)lib_linked_list	\
			$(LIBDIR)lib_file		\

LIBRARIES       =       $(SRC_LIB:%=-l%)
#LIB_PATHS_FLAG  =       $(LIB_PATHS:%=-L%)

LDFLAGS		=	-L./lib $(LIBRARIES)

all:            title $(NAME)

title:
		@$(ECHO)
		@$(ECHO) $(BOLD) $(YELLOW) Building $(NAME)$(DEFAULT)
		@$(ECHO)

$(NAME):        $(OBJ)
		@$(ECHO)
		@for MAKE_PATH in $(LIB_PATHS) ; do \
			make -C $$MAKE_PATH -s ; \
		done
		@$(ECHO)
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

force:		CFLAGS = -W -Wall -Wextra $(INCLUDE)
force:		re

%.o :		%.c
		@gcc -c -o $@ $^ $(CFLAGS) && $(ECHO) -n $(BOLD) $(GREEN)"  [OK] "$(WHITE) || $(ECHO) -n $(BOLD) $(RED)"  [KO] "$(WHITE) && $(ECHO) $(BOLD) $< | rev | cut -d'/' -f 1 | rev

.PHONY:		all title clean fclean re tests_run debug
