#include "mlx/mlx.h"
#include "so_long.h"

void open_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->column * 64, game->row * 64, "so_long");
}

void create_game(t_game *game)
{
	open_window(game);
}