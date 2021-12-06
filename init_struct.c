/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:24:35 by lcharlet          #+#    #+#             */
/*   Updated: 2021/12/06 22:02:08 by lcharlet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_struct(t_game *game)
{
	game->map = NULL;
	game->map = malloc(1000000);
	game->row = 0;
	game->column = 0;
	game->steps = 0;
	game->count_collect = 0;
	delete_flags_player(game);
	return (1);
}
