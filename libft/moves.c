/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:59:28 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/10/16 12:06:15 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	number_of_moves(t_data *data)
{
	data->player.nmoves++;
	if (data->player.nmoves > 999)
		end_screen(data, 1);
	data->player.hundreds = data->player.nmoves / 100;
	data->player.tens = (data->player.nmoves % 100) / 10;
	data->player.units = data->player.nmoves % 10;
	ft_printf("%d\n", data->player.nmoves);
	mlx_put_image_to_window(data->mlx, data->win,
		data->nbr[data->player.hundreds].iptr, (data->map.counter_pos), 0);
	mlx_put_image_to_window(data->mlx, data->win,
		data->nbr[data->player.tens].iptr, (data->map.counter_pos + 21), 0);
	mlx_put_image_to_window(data->mlx, data->win,
		data->nbr[data->player.units].iptr, (data->map.counter_pos + 42), 0);
}

void	move_direction(t_data *data, int x, int y)
{
	if (data->player.direction == RIGHT)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->right[data->player.current_frame].iptr, x * BSIZE, y * BSIZE);
	}
	else if (data->player.direction == LEFT)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->left[data->player.current_frame].iptr, x * BSIZE, y * BSIZE);
	}
}

void	basic_move(t_data *data, int new_x, int new_y)
{
	if (data->door_pos.in_door)
	{
		data->map.map[data->player.y][data->player.x] = 'E';
		mlx_put_image_to_window(data->mlx, data->win, data->map_img[3].iptr,
			data->player.x * BSIZE, data->player.y * BSIZE);
		data->door_pos.in_door = 0;
	}
	else
	{
		data->map.map[data->player.y][data->player.x] = '0';
		mlx_put_image_to_window(data->mlx, data->win, data->map_img[0].iptr,
			data->player.x * BSIZE, data->player.y * BSIZE);
	}
	data->map.map[new_y][new_x] = 'P';
	move_direction(data, new_x, new_y);
	data->player.x = new_x;
	data->player.y = new_y;
	number_of_moves(data);
}

void	move(t_data *data, int new_x, int new_y, char block)
{
	basic_move(data, new_x, new_y);
	if (block == 'C')
		data->map.coin_count--;
	else if (block == 'X')
	{
		end_screen(data, 1);
		return ;
	}
	else if (block == 'E' && data->map.coin_count == 0)
	{
		end_screen(data, 0);
		return ;
	}
	else if (data->map.coin_count == 0)
	{
		data->map.door_status = 1;
		mlx_put_image_to_window(data->mlx, data->win, data->map_img[4].iptr,
			data->door_pos.x * BSIZE, data->door_pos.y * BSIZE);
	}
}

void	move_player(t_data *data, int new_x, int new_y, int direction)
{
	if (direction == LEFT || direction == RIGHT)
		data->player.direction = direction;
	if (data->map.map[new_y][new_x] == '0')
		move(data, new_x, new_y, '0');
	else if (data->map.map[new_y][new_x] == 'C')
		move(data, new_x, new_y, 'C');
	else if (data->map.map[new_y][new_x] == 'X')
		move(data, new_x, new_y, 'X');
	else if (data->map.map[new_y][new_x] == 'E')
	{
		move(data, new_x, new_y, 'E');
		if (!data->map.door_status)
			data->door_pos.in_door = 1;
	}
}
