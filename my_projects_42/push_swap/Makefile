NAME	=	push_swap

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

OBJDIR	=	obj
SRCDIR	=	src
LIBDIR	=	libft

HEADER	=	push_swap.h

SRC		=	$(SRCDIR)/main.c	\
			$(SRCDIR)/args_operations.c	\
			$(SRCDIR)/min_sort.c	\
			$(SRCDIR)/Push_swap.c	\
			$(SRCDIR)/prepeare.c	\
			$(SRCDIR)/rotate.c	\
			$(SRCDIR)/score_1.c	\
			$(SRCDIR)/score_2.c	\
			$(SRCDIR)/stack_operations.c \
			$(SRCDIR)/the_rules_1.c	\
			$(SRCDIR)/the_rules_2.c	\
			$(SRCDIR)/utils.c

OBJ		=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))

LIBFT	=	libft.a

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			@printf "\nCompiling libft ...\n"
			@make -C $(LIBDIR)/
			@cp $(LIBDIR)/$(LIBFT) ./
			@printf "DONE libft!\n\nCompiling push_swap ...\n"
			@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
			@printf "DONE push_swap! \n\n"

$(OBJDIR)/$(SRCDIR)/%.o: 	$(SRCDIR)/%.c $(HEADER)
				@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR) :
	@mkdir $@ $@/$(SRCDIR)

$(OBJ) : | $(OBJDIR)

clean:
	@printf "clean... \n"
	@make fclean -C $(LIBDIR)/
	@rm -rf $(OBJDIR)

fclean: clean
	@printf "fclean... \n"
	@rm -rf $(NAME)
	@rm -f $(LIBFT)

re: fclean all