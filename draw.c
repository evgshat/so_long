#include "mlx/mlx.h"
#include "so_long.h"

int draw(t_game *game)
{
	int i = 0;
	while (game->map[i] != '\0')
	{
		if (game->map[i] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->wall, i * 64, i * 64);
		if (game->map[i] == 'C')
			mlx_put_image_to_window(game->mlx, game->win, game->food, i * 64, i * 64);
		if (game->map[i] == 'P')
			mlx_put_image_to_window(game->mlx, game->win, game->player, i * 64, i * 64);
		if (game->map[i] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->exit, i * 64, i * 64);
		if (game->map[i] == '0')
			mlx_put_image_to_window(game->mlx, game->win, game->empty, i * 64, i * 64);
		i++;
	}
	return (0);
}