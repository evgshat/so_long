#include "mlx/mlx.h"
#include "so_long.h"

int	can_move(int button, t_game *game)
{
	int i;
	int j;

	i = game->pl_i;
	j = game->pl_j;

	if (button == W)
	{
		if (game->map[--i][j] == '1')
			return (FALSE);
	}
	else if (button == S)
	{
		if (game->map[++i][j] == '1')
			return (FALSE);
	}
	else if (button == D)
	{
		if (game->map[i][++j] == '1')
			return (FALSE);
	}
	else if (button == A)
	{
		if (game->map[i][--j] == '1')
			return (FALSE);
	}
	return (TRUE);
}
