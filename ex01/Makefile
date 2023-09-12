NAME					=	fixed

SRCDIR					=	./
INCLUDEDIR				=	./

SRCFILES				=	main.cpp		\
							Fixed.cpp		\

SRCS					=	$(addprefix $(SRCDIR), $(SRCFILES))

CC						=	c++
CFLAGS					=	-Wall -Wextra -Werror -std=c++98 -pedantic
RM						=	rm -f

all:					$(NAME)

$(NAME):				$(SRCS)
							$(CC) $(CFLAGS) $(SRCS) -I $(INCLUDEDIR) -o $(NAME)

clean:
							$(RM) $(NAME)

fclean:					clean

re:						fclean all
