/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:23:44 by lcharlet          #+#    #+#             */
/*   Updated: 2021/12/06 20:39:05 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_row(t_game *game)
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
