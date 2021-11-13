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
// нет ни одного с - ошибка							-- check_c
// нет ни одного е - ошибка							-- check_e
// нет ни одного p - ошибка							-- check_p
// не прямоугольник (квадрат может быть) - ошибка	-- check_rectangular
// первая линия - стена								-- check_first_and_last_line
// последняя линия - стенами						--

#include "so_long.h"
#include "get_next_line.h"

static int	check_first_and_last_line(char *first_line);
static int	check_first_and_last_ch(char *line);
static int	check_rectangular(size_t len_prev_str, char *line);
static int	check_c(char *line);
static int	check_e(char *line);
static int	check_p(char *line);
static int	check_wrong_ch(char *line);

int	check_map(int a)
{
	char		*line;
	int			count_line;
	int			fd;
	int			all_check;
	int			flag_e;
	int			flag_c;
	int			flag_p;
	size_t		len_prev_line;

	count_line = 0;
	len_prev_line = 0;
	flag_e = 0;
	flag_c = 0;
	flag_p = 0;
	fd = open("map.ber", O_RDONLY);
	line = get_next_line(fd);
	len_prev_line = ft_strlen(line);
	while (line)
	{
		count_line++;
		all_check = check_rectangular(len_prev_line, line);
		if (all_check < 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		all_check = check_first_and_last_ch(line);
		if (all_check < 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		if (count_line == 1)
		{
			all_check = check_first_and_last_line(line);
			if (all_check < 0)
			{
				write(1, "Error\n", 6);
				return (0);
			}
		}
		all_check = check_wrong_ch(line);
			if (all_check < 0)
			{
					write(1, "Error\n", 6);
					return (0);
			}
		flag_e += check_e(line);
		flag_c += check_c(line);
		flag_p += check_p(line);
		printf("%s", line);
		line = get_next_line(fd);
	}
	if (flag_e != 1 || flag_c != 1 || flag_p != 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (a);
}

static int check_wrong_ch(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'E' && line[i] != 'P' && line[i] != 'C')
			return (-1);
		i++;
	}
	return (0);
}

static int	check_first_and_last_line(char *first_line)
{
	int	i;

	i = 0;
	while(first_line[i] != '\n')
	{
		if (first_line[i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

static int	check_first_and_last_ch(char *line)
{
	int		i;
	size_t	len_line;

	i = 0;
	len_line = ft_strlen(line);
	if (line[i] != '1' || line[len_line - 2] != '1')
		return (-1);
	else
		return (0);
}

static int	check_e(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] == 'E')
			return (1);
		i++;
	}
	return (0);
}

static int	check_c(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] == 'C')
			return (1);
		i++;
	}
	return (0);
}

static int	check_p(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] == 'P')
			return (1);
		i++;
	}
	return (0);
}


static int	check_rectangular(size_t len_prev_line, char *line)
{
	size_t len_line;

	len_line = ft_strlen(line);
	if (len_prev_line != len_line)
		return (-1);
	else
		return (0);
}

int main()
{
	check_map(10);
}

// 1) прочитать первую линию, убедиться, что там все единицы
// 2) в каждой линии проверять, что первый и последний символы - единица
// 3) если нашли e, p и c - записывать в check_flag. если он не равен трем, карта не валидна -- не работает
// 4) подсчитывать кол-во символов в каждой строке и сверяться со следующей, если не равны - ошибка
// 5) если меньше трех линий - ошибка. мб в глобальной переменной считать кол-во линий