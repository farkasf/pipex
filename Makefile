NAME = pipex
SRC = 	pipex.c \
	pipex_utils.c
OBJS = $(SRC:.c=.o)
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror
CC = cc
INCL = pipex.h
R = rm -f

all: $(NAME)

$(NAME):
	make all -C ./libft
	$(CC) $(CFLAGS) -c $(SRC) -I $(INCL)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	${MAKE} clean -C ./libft
	$(R) $(OBJS)

fclean:	clean
	$(R) $(NAME)
	${MAKE} fclean -C ./libft

re: fclean all