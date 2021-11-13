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

static int	check_map(char *map);
static int	check_wrong_ch(char *map);
static int	check_first_line(char *map);
static int	check_last_line(char *map);
static int	check_first_and_last_ch(char *map);

char	*create_map(int a)
{
	char	*map;
	int		fd;
	char	ch;
	int		was_read;
	int		i;

	was_read = 0;
	i = 0;
	map = malloc(100000);
	if (map == 0)
		return (NULL);
	fd = open("map.ber", O_RDONLY);
	was_read = read(fd, &ch, 1);
	if (was_read == 0)
		return (NULL);
	while (was_read != 0)
	{
		map[i] = ch;
		i++;
		was_read = read(fd, &ch, 1);
	}
	if ((check_map(map)) < 0)
		return (NULL);
	else
		return (map);
}

static int	check_map(char *map)
{
	int	check;

	check = 0;
	check = check_wrong_ch(map);
	if (check < 0)
		return (-1);
	check = check_first_line(map);
	if (check < 0)
		return (-1);
	check = check_last_line(map);
	if (check < 0)
		return (-1);
	check = check_first_and_last_ch(map);
	if (check < 0)
		return (-1);
	return (0);
}

static int check_wrong_ch(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] != '0' && map[i] != '1' && map[i] != 'E' && map[i] != 'P' && map[i] != 'C' && map[i] != '\n')
			return (-1);
		i++;
	}
	return (0);
}

static int	check_first_line(char *map)
{
	int	i;

	i = 0;
	while(map[i] != '\n')
	{
		if (map[i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

static int	check_last_line(char *map)
{
	int	i;

	i = 0;
	while(map[i] != '\0')
		i++;
	i--;
	while (map[i] != '\n')
	{
		if (map[i] != '1')
			return (-1);
		i--;
	}
	return (0);
}

static int	check_first_and_last_ch(char *map)
{
	int	i;

	i = 0;
	while(map[i] != '\n')
		i++;
	i--;
	if (map[i] != '1')
			return (-1);
	i--;
	while (i >= 0)
	{
		if (map[i - 1] == '\n')
		{
			if (map[i] != '1')
				return (-1);
		}
		if (i == 0)
		{
			if (map[i] == 1)
				return (0);
		}
		i--;
	}
	return (0);
}

int main()
{
	char	*map;

	map = create_map(10);
	printf("%s", map);
	free(map);
}