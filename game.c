#include "mlx/mlx.h"
// # include "mlx/mlx_int.h"
#include "so_long.h"

int	main()
{
	t_game	game;
	// прочитать и проверить карту
	init_struct(&game); // инициализация моей структуры
	create_map(&game);
	printf("%s", game.map);
	create_game(&game);
	init_img(&game);
	mlx_loop_hook(game.mlx, &draw, &game);
	mlx_loop(game.mlx); // зацикливаем окно

}

// debug("create_game_end\n", DEBUG);
// debug("mlx_loop_hook_end\n", DEBUG);
// debug("init_struct_end\n", DEBUG);