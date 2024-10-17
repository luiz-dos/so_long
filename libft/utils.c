/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:59:40 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/10/14 11:59:41 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	check_map_existence(char *file_name)
{
	int	fd;
	int	len;

	len = 0;
	while (file_name[len] != '\0')
		len++;
	if (len > 4 && file_name[len - 4] == '.' && file_name[len - 3] == 'b'
		&& file_name[len - 2] == 'e' && file_name[len - 1] == 'r')
	{
		fd = open(file_name, O_RDONLY);
		if (fd < 0)
		{
			ft_printf("Error\nCould not open file %s\n", file_name);
			exit(1);
		}
		close(fd);
	}
	else
	{
		ft_printf("Error\nThe map file must be .ber\n");
		exit(1);
	}
}

void	get_pos(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->map.h)
	{
		x = -1;
		while (++x < data->map.w)
		{
			if (data->map.map[y][x] == 'P')
			{
				data->player.x = x;
				data->player.y = y;
			}
			else if (data->map.map[y][x] == 'E')
			{
				data->door_pos.x = x;
				data->door_pos.y = y;
			}
		}
	}
}

void	get_pos_enemies(t_data *data)
{
	int	x;
	int	y;
	int	index;

	data->enemies = malloc(sizeof(t_enemy) * data->map.enemy_count);
	if (!data->enemies)
		free_exit(data, "Error\nMalloc error\n");
	y = -1;
	index = 0;
	while (++y < data->map.h)
	{
		x = -1;
		while (++x < data->map.w)
		{
			if (data->map.map[y][x] == 'X' && index < data->map.enemy_count)
			{
				data->enemies[index].x = x;
				data->enemies[index].y = y;
				index++;
			}
		}
	}
}
