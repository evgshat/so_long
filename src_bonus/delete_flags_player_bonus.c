/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_flags_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:23:59 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/06 16:30:02 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	delete_flags_player(t_game *game)
{
	game->flag_right = 0;
	game->flag_left = 0;
	game->flag_front = 0;
	game->flag_back = 0;
}
