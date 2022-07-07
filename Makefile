NAME	=	pipex

SRCS	=	pipex.c utils.c

HEADER	=	pipex.h

OBJ		=	$(SRCS:%.c=%.o)

CC		=	gcc

LIB		=	libft/libft.a

INCLUDE	= -I

FLAGS	=	-Wall -Wextra -Werror

.PHONY	:	all clean fclean re bonus libft

all		:	libft $(NAME)

libft	:
			@$(MAKE) -C libft/

$(NAME)	:	$(OBJ)
				$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

%.o		:	%.c $(HEADER)
			$(CC) $(FLAGS) -c $< -o $@

clean	:
			@make clean -C ./libft
			@rm -rf $(OBJ)

fclean	:	clean
			@make fclean -C ./libft
			@$(RM) $(NAME)

re		:	fclean all