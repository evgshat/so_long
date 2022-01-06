SRCS = ./src/game.c \
		./src/init_struct.c \
		./src/create_game.c \
		./src/check_map.c \
		./src/_check_map.c \
		./src/draw.c \
		./src/init_img.c \
		./src/get_next_line.c \
		./src/get_next_line_utils.c \
		./src/count_row.c \
		./src/position_player.c \
		./src/move.c \
		./src/can_move.c \
		./src/close_game.c \
		./src/delete_flags_player.c \
		./src/count_collect.c \
		./src/collect.c \
		./src/error.c \
		./src/utils.c \

SRCS_B = ./src_bonus/game_bonus.c \
		./src_bonus/init_struct_bonus.c \
		./src_bonus/create_game_bonus.c \
		./src_bonus/check_map_bonus.c \
		./src_bonus/_check_map_bonus.c \
		./src_bonus/draw_bonus.c \
		./src_bonus/init_img_bonus.c \
		./src_bonus/get_next_line_bonus.c \
		./src_bonus/get_next_line_utils_bonus.c \
		./src_bonus/count_row_bonus.c \
		./src_bonus/position_player_bonus.c \
		./src_bonus/move_bonus.c \
		./src_bonus/can_move_bonus.c \
		./src_bonus/close_game_bonus.c \
		./src_bonus/delete_flags_player_bonus.c \
		./src_bonus/count_collect_bonus.c \
		./src_bonus/collect_bonus.c \
		./src_bonus/error_bonus.c \
		./src_bonus/utils_bonus.c \

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

NAME = so_long
NAME_B = so_long_bonus
CFLAGS = -Werror -Wall -Wextra -g
CC = gcc
RM = rm -rf
FRAMEWORK	=	-Lmlx -lm -lmlx -framework OpenGL -framework AppKit
HEADER = so_long.h
HEADER_B = so_long_bonus.h

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FRAMEWORK) -o $(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME_B) : $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) $(FRAMEWORK) -o $(NAME_B)

%.o: %.c $(HEADER_B) Makefile
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

bonus: $(NAME_B)

clean:
		make -C ./mlx clean
		$(RM) $(OBJS) $(OBJS_B)

fclean:	clean
		$(RM) $(NAME) $(NAME_B)

re:	fclean all

.PHONY: all clean fclean re bonus