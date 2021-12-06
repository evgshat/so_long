/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:22:40 by lcharlet          #+#    #+#             */
/*   Updated: 2021/12/06 21:54:50 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

static int	len_first_line(char *line, t_game *game)
{
	int	len_first_line;

	len_first_line = ft_strlen(line);
	game->column = len_first_line - 1;
	return (len_first_line);
}

void	init_struct_map(t_check *check, t_game *game)
{
	check->count_line = 0;
	check->i = 0;
	check->len_prev_line = 0;
	check->fd = open("map.ber", O_RDONLY);
	check->line = get_next_line(check->fd);
	if (check->line == NULL)
		error("Empty map\n");
	check->len_first = len_first_line(check->line, game);
	check->count_line++;
	game->map[check->i] = check->line;
	check->i++;
}

static void	check_wrong_ch(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != '0' && line[i] != '1'
			&& line[i] != 'E' && line[i] != 'P' && line[i] != 'C')
			error("Wrong symbols\n");
		i++;
	}
}

static void	check_first_and_last_ch(char *line)
{
	int		i;
	size_t	len_line;

	i = 0;
	len_line = ft_strlen(line);
	if (line[i] != '1' || line[len_line - 2] != '1')
		error("Map without wall\n");
}

void	check_map(t_game *game)
{
	t_check	check;

	init_struct_map(&check, game);
	while (check.line)
	{
		check_rectangular(check.len_first, check.line, check.count_line, game);
		check_first_and_last_ch(check.line);
		if (check.count_line == 1 || check.count_line == game->row)
			check_first_and_last_line(check.line);
		check_wrong_ch(check.line);
		check.line = get_next_line(check.fd);
		game->map[check.i] = check.line;
		check.i++;
		check.count_line++;
	}
	_check_map(game);
}
