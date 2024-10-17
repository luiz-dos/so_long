/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:58:46 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/10/16 12:08:43 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	check_format(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.map[i])
	{
		if ((int)ft_strlen(data->map.map[i]) != data->map.w)
			map_error(data, "Error\nThe map is not rectangular\n");
		i++;
	}
}

void	check_walls(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.map[0][i])
	{
		if (data->map.map[0][i] != '1' || data->map.map[data->map.h
			- 1][i] != '1')
			map_error(data, "Error\nThe map is not fenced\n");
		i++;
	}
	i = 0;
	while (i < data->map.h)
	{
		if (data->map.map[i][0] != '1' || data->map.map[i][data->map.w
			- 1] != '1')
			map_error(data, "Error\nThe map is not fenced\n");
		i++;
	}
}

void	check_map_composition(t_data *data)
{
	int	h;
	int	w;

	h = 0;
	while (data->map.map[h])
	{
		w = 0;
		while (data->map.map[h][w])
		{
			if (data->map.map[h][w] != '0' && data->map.map[h][w] != '1'
				&& data->map.map[h][w] != 'C' && data->map.map[h][w] != 'E'
				&& data->map.map[h][w] != 'P' && data->map.map[h][w] != 'X')
				map_error(data, "Error\nWrong map composition\n");
			w++;
		}
		h++;
	}
}

void	map_is_valid(t_data *data)
{
	if (data->map.player_count != 1)
		map_error(data, "Error\nThere must be only one player\n");
	if (data->map.exit_count != 1)
		map_error(data, "Error\nThere must be only one exit door\n");
	if (data->map.coin_count <= 0)
		map_error(data, "Error\nThere must be at least one coin\n");
	if (data->map.fspace_count <= 0)
		map_error(data, "Error\nThere must be at least one empty space\n");
}

void	check_map(t_data *data)
{
	check_format(data);
	check_walls(data);
	check_map_composition(data);
	map_is_valid(data);
	check_map_path(data);
}
