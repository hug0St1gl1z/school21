# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cblanca <cblanca@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 13:26:50 by cblanca           #+#    #+#              #
#    Updated: 2021/11/27 15:58:06 by cblanca          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

LIBFT =	./libft/libft.a

OBGS =	ft_printf.c \
		src/ft_case_c.c \
		src/ft_case_d_or_i.c \
		src/ft_case_s.c \
		src/ft_case_p.c \
		src/ft_case_u.c 

OBJ = $(patsubst %.c,%.o,$(OBGS))

CC = gcc

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) all -C ./libft
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $?

%.o : %.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(MAKE) clean -C ./libft
	@rm -f $(OBJ)

fclean : clean
	$(MAKE) fclean -C ./libft
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re