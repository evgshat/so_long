#include "mlx/mlx.h"
#include "so_long.h"

int draw(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	mlx_clear_window(game->mlx, game->win);
	while (i < game->row)
	{
		j = 0;
		while (j < game->column)
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, j * 64, i * 64);
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->food, j * 64, i * 64);
			if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player, j * 64, i * 64);
			if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit, j * 64, i * 64);
			if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->empty, j * 64, i * 64);
			j++;
		}
		i++;
	}
	return (0);
}