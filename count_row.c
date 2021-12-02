#include "so_long.h"

void count_row(t_game *game)
{
	int		fd;
	char	*line;

	fd = open("map.ber", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		game->row++;
	}
}