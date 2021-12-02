#include "so_long.h"

void	position_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->row)
	{
		j = 0;
		while (j < game->column)
		{
			if (game->map[i][j] == 'P')
			{
				game->pl_i = i;
				game->pl_j = j;
				return ;
			}
			j++;
		}
		i++;
	}
}