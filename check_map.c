// 0 - empty
// 1 - wall
// C - collectible
// E - explicit
// P - player's starting position
// программа принимает первым аргуменнтом мою карту .ber

// не закрыта стенами - ошибка
// другой символ - ошибка
// не формат .ber - ошибка
// пустая карта - ошибка
// нет ни одного с - ошибка
// нет ни одного е - ошибка
// нет ни одного p - ошибка
// не прямоугольник (квадрат может быть) - ошибка

// Вот весь код по гнл:
// int get_next_line(char **line)
// {
//  int rd = 0;
//  int i = 0;
//  char ch;
//  char *buffer = malloc(100000);
//  *line = buffer;
//  while ((rd = read(0, &ch, 1)) > 0 && ch != '\n')
//  buffer[i++] = ch;
//  buffer[i] = '\0';
//  return (rd);
// }

#include "so_long.h"
#include "get_next_line.h"

static int	check_first_and_last_line(char *first_line);
static int	check_first_and_last_ch(char *line);
static int	check_e_c_p(char *line);
static int	check_rectangular(size_t len_prev_str, char *line);

int	check_map(int a)
{
	char		*line;
	int			count_line;
	int			fd;
	int			all_check;
	int			flag_e_c_p;
	size_t		len_prev_line;

	count_line = 0;
	flag_e_c_p = 0;
	len_prev_line = 0;
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
		flag_e_c_p += check_e_c_p(line);
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
		printf("%s", line);
		line = get_next_line(fd);
	}
	if (flag_e_c_p < 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (a);
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

static int	check_e_c_p(char *line)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (line[i] != '\n')
	{
		if (line[i] == 'E' || line[i] == 'P' || line[i] == 'C')
			res++;
		i++;
	}
	return (res);
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
// 3) если нашли e, p и c - записывать в check_flag. если он не равен трем, карта не валидна
// 4) подсчитывать кол-во символов в каждой строке и сверяться со следующей, если не равны - ошибка
// 5) если меньше трех линий - ошибка. мб в глобальной переменной считать кол-во линий