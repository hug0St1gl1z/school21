NAME	=	libft.a
SRC		=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strlen.c
OBJ		=	${SRC:.c=.o}
B_SRC	=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
B_OBJ	=	${B_SRC:.c=.o}
HEADER	=	libft.h
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g

all:		$(NAME)

$(NAME):	${OBJ} ${B_OBJ}
			ar rc $(NAME) ${OBJ} ${B_OBJ}
			ranlib $(NAME)

bonus:		${B_OBJ}
			ar rc $(NAME) ${B_OBJ}
			ranlib $(NAME)

clean:
			rm -f *.o

fclean:		clean
			rm -f $(NAME)

re:			fclean all

run: $(NAME)
	gcc main.c -fsanitize=address libft.a
	./a.out

.PHONY:		all clean fclean bonus re
