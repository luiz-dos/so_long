/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:59:25 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/10/16 11:52:11 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	basic_enemy_move(t_data *data, int i, int new_x, int new_y)
{
	data->map.map[data->enemies[i].y][data->enemies[i].x] = '0';
	mlx_put_image_to_window(data->mlx, data->win, data->map_img[0].iptr,
		data->enemies[i].x * BSIZE, data->enemies[i].y * BSIZE);
	data->enemies[i].x = new_x;
	data->enemies[i].y = new_y;
	data->map.map[new_y][new_x] = 'X';
	mlx_put_image_to_window(data->mlx, data->win,
		data->enemy[data->map.enemy_direction].iptr, data->enemies[i].x * BSIZE,
		data->enemies[i].y * BSIZE);
}

void	choose_a_move(t_data *data, int i)
{
	int	new_x;
	int	new_y;

	data->map.enemy_direction = rand() % 4;
	new_x = data->enemies[i].x;
	new_y = data->enemies[i].y;
	if (data->map.enemy_direction == RIGHT)
		new_x++;
	else if (data->map.enemy_direction == LEFT)
		new_x--;
	else if (data->map.enemy_direction == 3)
		new_y--;
	else
		new_y++;
	if (data->map.map[new_y][new_x] == '0'
		|| data->map.map[new_y][new_x] == 'P')
	{
		if (data->map.map[new_y][new_x] == 'P')
			data->game_over = 1;
		basic_enemy_move(data, i, new_x, new_y);
	}
}

void	move_enemies(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.enemy_count)
	{
		choose_a_move(data, i);
		i++;
	}
}
