NAME=philo_bonus

CC=gcc
FLAGS=-Wall -Werror -Wextra -pthread

SRC=main.c utils.c input.c actions.c philosopher.c monitor.c launch.c

RM=rm -rf

all: $(NAME)

$(NAME): $(SRC:.c=.o)
	$(CC) $(FLAGS) $(SRC:.c=.o) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	$(RM) $(SRC:.c=.o)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re