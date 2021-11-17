#include "mlx/mlx.h"
#include <stdio.h>

int	main()
{
	void	*mlx;
	void	*mlx_win;
	void	*img; // указатель на изображение
	void	*addr;
	int		bits_per_pixel = 1;
	int		endian = 0;
	int		line_length = 10;
	int		x = 25;
	int		y = 25;
	char	*dst;
	int		color = 0x0000FF00;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello");
	img = mlx_new_image(mlx, 1920, 1080); // указатель на изображение
	addr = mlx_get_data_addr(img, &bits_per_pixel, &line_length, &endian); // адрес памяти изображения
	// img
	while (x <= 125)
	{
		while (y <= 125)
		{
			dst = addr + (y * line_length + x * (bits_per_pixel / 8));
			*(unsigned int*)dst = color;
			y++;
		}
		y = 25;
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0); // поместить изображение
	x = 125;
	y = 125;
	color = 0x00FF0000;
	while (x <= 500)
	{
		while (y <= 300)
		{
			dst = addr + (y * line_length + x * (bits_per_pixel / 8));
			*(unsigned int*)dst = color;
			y++;
		}
		y = 25;
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0); // поместить изображение
	mlx_loop(mlx);
}