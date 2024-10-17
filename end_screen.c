/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:58:58 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/10/16 12:44:54 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	wait_and_exit(t_data *data)
{
	if (data->map.end_screen_time > 0)
		data->map.end_screen_time--;
	else
	{
		if (data->result)
			free_exit(data, "You lose");
		else
			free_exit(data, "You win");
	}
	return (0);
}

void	update_enemy_images(t_data *data, int result)
{
	int	i;

	i = 0;
	while (i < data->map.enemy_count)
	{
		if (result)
			mlx_put_image_to_window(data->mlx, data->win, data->enemy[5].iptr,
				data->enemies[i].x * BSIZE, data->enemies[i].y * BSIZE);
		else
			mlx_put_image_to_window(data->mlx, data->win, data->enemy[4].iptr,
				data->enemies[i].x * BSIZE, data->enemies[i].y * BSIZE);
		i++;
	}
}

void	end_screen(t_data *data, int result)
{
	update_enemy_images(data, result);
	mlx_put_image_to_window(data->mlx, data->win, data->end_screen[result].iptr,
		(data->map.counter_pos - 64), (((data->map.h * BSIZE) / 2) - 64));
	data->game_over = 1;
	data->map.end_screen_time = 20000;
	data->result = result;
	mlx_loop_hook(data->mlx, &wait_and_exit, data);
}
