#include "mlx/mlx.h"
#include "so_long.h"

// printf("%d, %d", game->pl_x, game->pl_y);

void	move_w(t_game *game);
void	move_s(t_game *game);
void	move_d(t_game *game);
void	move_a(t_game *game);

int	move(int button, t_game *game)
{
	int res;

	res = can_move(button, game);
	if (button == 53)
		close_game(game);
	if (res == TRUE)
	{
		if (button == W)
			move_w(game);
		else if (button == S)
			move_s(game);
		else if (button == D)
			move_d(game);
		else if (button == A)
			move_a(game);
	}
	return (0);
}

void	move_w(t_game *game)
{
	game->map[game->pl_i][game->pl_j] = '0';
	game->map[--game->pl_i][game->pl_j] = 'P';
	delete_flags_player(game);
	game->flag_back = 1;
	game->steps++;
}

void	move_s(t_game *game)
{
	game->map[game->pl_i][game->pl_j] = '0';
	game->map[++game->pl_i][game->pl_j] = 'P';
	delete_flags_player(game);
	game->flag_front = 1;
	game->steps++;
}

void	move_d(t_game *game)
{
	game->map[game->pl_i][game->pl_j] = '0';
	game->map[game->pl_i][++game->pl_j] = 'P';
	delete_flags_player(game);
	game->flag_right = 1;
	game->steps++;
}

void	move_a(t_game *game)
{
	game->map[game->pl_i][game->pl_j] = '0';
	game->map[game->pl_i][--game->pl_j] = 'P';
	delete_flags_player(game);
	game->flag_left = 1;
	game->steps++;
}