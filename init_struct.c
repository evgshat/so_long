#include "mlx/mlx.h"
// #include "mlx/mlx_int.h"
#include "so_long.h"

int init_struct(t_game *game)
{
	game->map = NULL;
	game->map = malloc(1000000);
	game->row = 0;
	game->column = 0;
	game->steps = 0;
	delete_flags_player(game);
	// game->coord_x = 0;
	// game->coord_y = 0;
	// game->mlx = mlx_init();
	// game->mlx_win = mlx_new_window(game->mlx, 1920, 1080, "Hello"); // создаем окно
	// game->w = 1920;
	// game->h = 1080;
	// game->img = mlx_new_image(game->mlx, game->w, game->h); // указатель на изображение
	// addr = mlx_get_data_addr(img, &bits_per_pixel, &line_length, &endian); // адрес памяти изображения
	// mlx_loop(game->mlx); // зацикливаем окно
	return (1);
}
