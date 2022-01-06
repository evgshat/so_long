/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:24:35 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/06 16:30:26 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	init_struct(t_game *game)
{
	game->map = NULL;
	game->map = (char **)malloc((game->row + 1) * sizeof(char *));
	game->column = 0;
	game->steps = 0;
	game->count_collect = 0;
	game->game_over = 0;
	delete_flags_player(game);
	return (1);
}
