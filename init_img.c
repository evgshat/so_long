#include "mlx/mlx.h"
#include "so_long.h"

void	init_img(t_game *game)
{
	int img_w = 10;
	int img_h = 10;
	game->food = mlx_xpm_file_to_image(game->mlx, "assets/food.xpm", &img_w, &img_h);
	game->player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", &img_w, &img_h);
	game->wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &img_w, &img_h);
	game->empty = mlx_xpm_file_to_image(game->mlx, "assets/temp.xpm", &img_w, &img_h);
	game->exit = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm", &img_w, &img_h);
}