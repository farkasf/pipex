NAME = pipex
SRC =  ./sources/pipex.c \
       ./sources/pipex_utils.c
OBJS = $(SRC:.c=.o)
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror
CC = cc
INCL = ./includes
R = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	make all -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCL)

clean:
	${MAKE} clean -C ./libft
	$(R) $(OBJS)

fclean: clean
	$(R) $(NAME)
	${MAKE} fclean -C ./libft

re: fclean all
