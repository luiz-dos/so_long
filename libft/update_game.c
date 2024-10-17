/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:43:28 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/10/16 12:44:04 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	update_enemies(t_data *data)
{
	data->map.enemy_move_time++;
	if (data->map.enemy_move_time >= data->map.enemy_move_delay)
	{
		move_enemies(data);
		data->map.enemy_move_delay = 8000;
		data->map.enemy_move_time = 0;
	}
}

void	update_player_animation(t_data *data)
{
	data->player.frame_time++;
	if (data->player.frame_time >= data->player.frame_delay)
	{
		data->player.current_frame = (data->player.current_frame + 1) % 6;
		data->player.frame_time = 0;
		move_direction(data, data->player.x, data->player.y);
	}
}

int	update_game(t_data *data)
{
	if (data->game_over == 1)
	{
		end_screen(data, 1);
		return (0);
	}
	update_enemies(data);
	update_player_animation(data);
	return (0);
}
