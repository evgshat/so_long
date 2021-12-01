// запихнем всю карту в одну линию

// 0 - empty
// 1 - wall
// C - collectible
// E - explicit
// P - player's starting position
// программа принимает первым аргуменнтом мою карту .ber

// не закрыта стенами - ошибка						-- check_first_and_last_ch
// другой символ - ошибка							-- check_wrong_ch
// не формат .ber - ошибка							-- хз, надо ли проверять
// пустая карта - ошибка							--
// нет ни одного с - ошибка							--
// нет ни одного е - ошибка							--
// нет ни одного p - ошибка							--
// не прямоугольник (квадрат может быть) - ошибка	--
// первая линия - стена								-- check_first_line
// последняя линия - стенами						-- check_last_line

#include "so_long.h"
#include "get_next_line.h"

static int	check_map(t_game *game);
static int	check_wrong_ch(t_game *game);
static int	check_first_line(t_game *game);
static int	check_last_line(t_game *game);
static int	check_first_and_last_ch(t_game *game);

int	create_map(t_game *game)
{
	int		fd;
	char	ch;
	int		was_read;
	int		i;

	was_read = 0;
	i = 0;
	game->map = malloc(100000);
	if (game->map == 0)
		return (-1);
	fd = open("map.ber", O_RDONLY);
	was_read = read(fd, &ch, 1);
	if (was_read == 0)
		return (-1);
	while (was_read != 0)
	{
		game->map[i] = ch;
		i++;
		was_read = read(fd, &ch, 1);
	}
	if ((check_map(game)) < 0)
		return (-1);
	else
		return (0);
}

static int	check_map(t_game *game)
{
	int	check;

	check = 0;
	check = check_wrong_ch(game);
	if (check < 0)
		return (-1);
	check = check_first_line(game);
	if (check < 0)
		return (-1);
	check = check_last_line(game);
	if (check < 0)
		return (-1);
	check = check_first_and_last_ch(game);
	if (check < 0)
		return (-1);
	return (0);
}

static int check_wrong_ch(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != '\0')
	{
		if (game->map[i] != '0' && game->map[i] != '1' && game->map[i] != 'E' && game->map[i] != 'P' && game->map[i] != 'C' && game->map[i] != '\n')
			return (-1);
		i++;
	}
	return (0);
}

static int	check_first_line(t_game *game)
{
	int	i;

	i = 0;
	while(game->map[i] != '\n')
	{
		if (game->map[i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

static int	check_last_line(t_game *game)
{
	int	i;

	i = 0;
	while(game->map[i] != '\0')
		i++;
	i--;
	while (game->map[i] != '\n')
	{
		if (game->map[i] != '1')
			return (-1);
		i--;
	}
	return (0);
}

static int	check_first_and_last_ch(t_game *game)
{
	int	i;

	i = 0;
	while(game->map[i] != '\n')
		i++;
	i--;
	if (game->map[i] != '1')
			return (-1);
	i--;
	while (i >= 0)
	{
		if (game->map[i - 1] == '\n')
		{
			if (game->map[i] != '1')
				return (-1);
		}
		if (i == 0)
		{
			if (game->map[i] == 1)
				return (0);
		}
		i--;
	}
	return (0);
}

// int main()
// {
// 	char	*map;

// 	map = create_map(10);
// 	printf("%s", map);
// 	free(map);
// }