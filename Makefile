NAME = libft.a

SRC = $(shell find . -name "*.c" ! -name "*_bonus.c")

SRC_BONUS = $(shell find . -name "*_bonus.c")

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

CFLAGS = -Wall -Werror -Wextra

COMPILE = gcc $(CFLAGS) -c

LIB = ar rc $(NAME)

RANLIB = ranlib $(NAME)

REMOVE = rm -f

all: $(NAME)

$(NAME):
	@$(COMPILE) $(SRC)
	@$(LIB) $(OBJ)
	@$(RANLIB)

bonus:
	@$(COMPILE) $(SRC_BONUS)
	@$(LIB) $(OBJ_BONUS)
	@$(RANLIB)

clean:
	@$(REMOVE) $(OBJ)

fclean: clean
	@$(REMOVE) $(NAME)

re: fclean all

so:
	gcc -fPIC -c $(SRC)
	gcc -shared -Wl,-soname,libft.so -o libft.so *.o
.PHONY: all clean fclean re