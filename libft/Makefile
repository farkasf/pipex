NAME = libft.a
SRC = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_cs.c \
	ft_dix.c \
	ft_get_next_line.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_printf.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin_gnl.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_up.c
SRC_B = ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c
OBJS = $(SRC:.c=.o)
OBJS_B = $(SRC_B:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = cc
INCL = libft.h
RLIB = ranlib
CLIB = ar rc
R = rm -f

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC) -I $(INCL)
	$(CLIB) $(NAME) $(OBJS)
	$(RLIB) $(NAME)

bonus:
	$(CC) $(CFLAGS) -c $(SRC_B) -I $(INCL)
	$(CLIB) $(NAME) $(OBJS_B)
	$(RLIB) $(NAME)

clean:
	$(R) $(OBJS)
	$(R) $(OBJS_B)

fclean:	clean
	$(R) $(NAME)

re: fclean all