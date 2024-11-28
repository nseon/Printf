NAME = test

SRC = test.c

LIBDIR = ../

CC = cc
CPPFLAGS = -I../
CFLAGS = -Wall -Werror -Wextra -g3

all : $(NAME)

$(NAME) : lib
	$(CC) $(CPPFLAGS) $(SRC) -L$(LIBDIR) -lftprintf -o $(NAME)

clean :
	$(MAKE) fclean -C $(LIBDIR)

lib : force
	$(MAKE) -C $(LIBDIR)

fclean : clean
	rm -f $(NAME)

force :

re : fclean all

.PHONY: all clean fclean re
