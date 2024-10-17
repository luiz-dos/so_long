/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:58:50 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/10/16 11:38:30 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	load_move_counter(t_data *data)
{
	data->map.counter_pos = ((data->map.w * BSIZE) / 2) - 32;
	mlx_put_image_to_window(data->mlx, data->win, data->nbr[0].iptr,
		data->map.counter_pos, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->nbr[0].iptr,
		(data->map.counter_pos + 21), 0);
	mlx_put_image_to_window(data->mlx, data->win, data->nbr[0].iptr,
		(data->map.counter_pos + 42), 0);
}

void	select_block(t_data *data, int h, int w, char c)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->map_img[1].iptr, w,
			h);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->map_img[0].iptr, w,
			h);
	else if (c == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->right[0].iptr, w,
			h);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->map_img[3].iptr, w,
			h);
	else if (c == 'X')
		mlx_put_image_to_window(data->mlx, data->win, data->enemy[0].iptr, w,
			h);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->map_img[2].iptr, w,
			h);
}

void	create_map(t_data *data)
{
	int	h;
	int	w;

	h = 0;
	while (data->map.map[h])
	{
		w = 0;
		while (data->map.map[h][w])
		{
			select_block(data, (h * BSIZE), (w * BSIZE), data->map.map[h][w]);
			w++;
		}
		h++;
	}
}
