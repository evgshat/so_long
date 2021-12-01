#ifndef SO_LONG_H
#define SO_LONG_H

#include <fcntl.h>
#include "mlx/mlx_int.h"
#include "mlx/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

# define TRUE			1
# define FALSE			0

// window
# define WIDTH			1000
# define HEIGHT			500
//

// debug
# define DEBUG			1
//


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
	char	*map;
	t_img	*player_temp;
	void	*food;
	void	*wall;
	void	*exit;
	void	*empty;
	void	*player;

} t_game;


int		init_struct(t_game *game);
void	create_game(t_game *game);
int		create_map(t_game *game);
int		draw(t_game *game);
void	debug(char *msg, int debug);
void	init_img(t_game *game);

#endif
