NAME = libftprintf.a

SRC = lens.c printf.c fill.c fcts.c

OBJ = $(SRC:.c=.o)

DEP = $(SRC:.c=.d)

MODE ?=
MODETRACE = .mt
LASTMODE = $(shell cat $(MODETRACE) 2>/dev/null)

CC = cc
CPPFLAGS = -MMD -MP
CFLAGS = -Wall -Werror -Wextra

ifneq ($(MODE), $(LASTMODE))
$(NAME): force
endif

all : $(NAME)

$(NAME) : $(OBJ)
	echo $(MODE) > $(MODETRACE)
	ar -rcs $@ $(OBJ)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

-include $(DEP)

clean :
	rm -f $(OBJ) $(DEP)

fclean : clean
	rm -f $(NAME)

force:

re : fclean all

.PHONY: bonus all clean fclean re force
