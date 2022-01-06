/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_collect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:23:22 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/06 16:29:37 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	no_collet_exit(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'E' && game->count_collect == 0)
		close_game(game);
}

void	is_collect(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'C')
		game->count_collect--;
	else if (game->map[i][j] == 'R')
		game->game_over = 1;
}
