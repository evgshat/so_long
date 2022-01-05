/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:02:51 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/05 19:09:04 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void is_enemy(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'R')
		mlx_put_image_to_window(game->mlx,
			game->win, game->empty, i * 64, j* 64);
}
