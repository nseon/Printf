NAME = test

SRC = test.c

LIBDIR = ../

CC = cc
CPPFLAGS = -I../
CFLAGS = -Wall -Werror -Wextra -g3

all : $(NAME)

$(NAME) :
	$(MAKE) -C $(LIBDIR)
	$(CC) $(CPPFLAGS) $(SRC) -L$(LIBDIR) -lftprintf -o $(NAME)

clean :
	$(MAKE) fclean -C $(LIBDIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
