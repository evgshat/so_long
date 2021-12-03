#include "mlx/mlx.h"
#include "so_long.h"

void delete_flags_player(t_game *game)
{
	game->flag_right = 0;
	game->flag_left = 0;
	game->flag_front = 0;
	game->flag_back = 0;
}