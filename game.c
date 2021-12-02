#include "mlx/mlx.h"
#include "so_long.h"

int	main()
{
	// int i = 0;
	t_game	game;
	init_struct(&game);
	count_row(&game);
	check_map(&game);
	create_game(&game);
	init_img(&game);
	position_player(&game);

	mlx_hook(game.win, PRESS, 0, &move, &game);
	mlx_hook(game.win, EXIT, 0, &close_game, &game);
	mlx_loop_hook(game.mlx, &draw, &game);
	mlx_loop(game.mlx);
}

// debug("create_game_end\n", DEBUG);
// debug("mlx_loop_hook_end\n", DEBUG);
// debug("init_struct_end\n", DEBUG);

// printf("строк = %d\n", game.row);
// 	printf("стоблцов = %d\n", game.column);
// 	while (i < game.row)
// 	{
// 		printf("%s", game.map[i]);
// 		i++;
// 	}

// printf("player = %d, %d, %c\n", game.pl_x, game.pl_y, game.map[game.pl_x][game.pl_y]);