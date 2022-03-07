SRC		=	main.c initialization.c\
			draw/draw_plane.c draw/raycast_dda.c\
			hooks/key_hooks.c hooks/movements.c hooks/rotation.c\
			parser/map_parser.c parser/gnl/get_next_line.c parser/gnl/get_next_line_utils.c\
			parser/parser_utils.c parser/parser_utils2.c validation/map_validation.c validation/validation_utils.c\
			utils/check_walls.c utils/draw_utils.c utils/common_utils.c utils/clear_utils.c\
			draw/draw_minimap.c utils/texture_utils.c utils/draw_minimap_utils.c
SRC_LIB	=	libft/ft_lstadd_back.c libft/ft_lstadd_front.c libft/ft_lstclear.c libft/ft_lstdelone.c libft/ft_lstiter.c libft/ft_lstlast.c libft/ft_lstmap.c libft/ft_lstnew.c libft/ft_lstsize.c\
			libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_isspace.c libft/ft_itoa.c libft/ft_memccpy.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strrev.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c libft/ft_strlen.c
OBJ		=	$(SRC:.c=.o)
NAME	=	cub3D
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -MMD -MP
LIBDIR	=	./libft
LIB		=	$(LIBDIR)/libft.a
LFLAGS	=	-L $(LIBDIR) -lft -lmlx -framework OpenGL -framework AppKit
HEADER	=	cub3D.h constants.h

DEPENDS := $(SRC:.c=.d)

.PHONY	:	all re clean fclean

all		:	$(NAME)

$(LIB)	:	$(SRC_LIB)
			make -s -C $(LIBDIR)

$(NAME)	:	$(OBJ) Makefile
			$(CC) $(CFLAGS) $(LFLAGS) $(OBJ)  -o $(NAME)

-include $(DEPENDS)

%.o		:	%.c $(LIB)
			$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

clean	:	
			rm -f *.o */*.o */*/*.o $(DEPENDS)
			make clean -C $(LIBDIR)

fclean	:	clean
			rm -f $(NAME)
			make fclean -C $(LIBDIR)

x		:	all
			./cub3D map.cub

re		:	fclean all
