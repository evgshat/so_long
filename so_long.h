#ifndef SO_LONG_H
#define SO_LONG_H

#include <fcntl.h>
#include "mlx/mlx_int.h"
#include "mlx/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

# define TRUE	1
# define FALSE	0

//

// debug
# define DEBUG	1
//

// button

# define W		13
# define S		1
# define A		0
# define D		2
# define ESC	53
# define PRESS	2
# define EXIT	17

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		h;
	int		w;
}			t_img;

typedef struct s_game
{
	void	*mlx_win;
	void	*mlx;
	void	*win;
	int		coord_x;
	int		coord_y;
	void	*img;
	char	**map;
	t_img	*player_temp;
	void	*food;
	void	*wall;
	void	*exit;
	void	*empty;
	void	*player;
	int		row;
	int		column;
	int		pl_i; //x
	int		pl_j;
	int		steps;

} t_game;


int		init_struct(t_game *game);
char	*get_next_line(int fd);
int		check_map(t_game *game);
void	create_game(t_game *game);
int		draw(t_game *game);
void	debug(char *msg, int debug);
void	init_img(t_game *game);
void	count_row(t_game *game);
void	position_player(t_game *game);
int		move(int button, t_game *game);
int		can_move(int button, t_game *game);
int		close_game(t_game *game);


#endif
