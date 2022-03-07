CLIENT	= client
SRC_C	= client.c utils.c
OBJ_C	= $(SRC_C:.c=.o)

SERVER	= server
SRC_S	= server.c utils.c
OBJ_S	= $(SRC_S:.c=.o)

INC		= ./

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

.PHONY: all clean fclean re

all:	$(CLIENT) $(SERVER)

$(CLIENT):	$(OBJ_C) minitalk.h Makefile
			$(CC) $(CFLAGS) $(OBJ_C) -I$(INC) -o $(CLIENT)

$(SERVER):	$(OBJ_S) minitalk.h Makefile
			$(CC) $(CFLAGS) $(OBJ_S) -I$(INC) -o $(SERVER)

clean:
	$(RM) $(OBJ_C) $(OBJ_S) $(CLIENT) $(SERVER)

fclean: clean
		$(RM) $(CLIENT) $(SERVER)

re: fclean all

