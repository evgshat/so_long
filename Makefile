SRCS = game.c

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

NAME = so_long
CFLAGS = -Werror -Wall -Wextra -g
CC = gcc
RM = rm -rf
FRAMEWORK	=	-Lmlx -lm -lmlx -framework OpenGL -framework AppKit

HEADER = so_long.h

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FRAMEWORK) -o $(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all:	@make -C mlx/ all
		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
