/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:23:54 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/06 16:30:03 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "mlx/mlx.h"
#include "so_long_bonus.h"

void	open_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			game->column * 64, game->row * 64, "so_long");
}

void	create_game(t_game *game)
{
	open_window(game);
}
