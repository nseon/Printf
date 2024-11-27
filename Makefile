NAME = libftprintf.a

SRC = lens.c printf.c fill.c fcts.c

OBJ = $(SRC:.c=.o)

DEP = $(SRC:.c=.d)

LIBDIR = Libft
LIBA = libft.a

CC = cc
CPPFLAGS = -MMD -MP
CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C $(LIBDIR)
	cp $(LIBDIR)/$(LIBA) $@
	ar -rcs $@ $(OBJ)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

-include $(DEP)

clean :
	rm -f $(OBJ) $(DEP)
	$(MAKE) fclean -C $(LIBDIR)

fclean : clean
	rm -f $(NAME) $(LIBA)

re : fclean all

.PHONY: all clean fclean re
