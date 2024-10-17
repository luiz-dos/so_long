/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:59:08 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/10/14 11:59:09 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	flood_fill(t_data *data, int x, int y, char **map_copy)
{
	if (data->map.map[y][x] == '1' || map_copy[y][x] == 'V')
		return ;
	map_copy[y][x] = 'V';
	flood_fill(data, x + 1, y, map_copy);
	flood_fill(data, x - 1, y, map_copy);
	flood_fill(data, x, y + 1, map_copy);
	flood_fill(data, x, y - 1, map_copy);
}

void	check_map_path_two(t_data *data, char **map_copy)
{
	int	i;
	int	j;

	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'C' || map_copy[i][j] == 'E')
			{
				free_matrix(map_copy);
				free_exit_two(data,
					"Error\nThere is no valid path on the map\n");
			}
			j++;
		}
		i++;
	}
	free_matrix(map_copy);
}

void	check_map_path(t_data *data)
{
	char	**map_copy;
	int		i;

	map_copy = (char **)malloc(sizeof(char *) * (data->map.h + 1));
	if (!map_copy)
		free_exit_two(data, "Error\nMalloc error\n");
	i = -1;
	while (++i < data->map.h)
	{
		map_copy[i] = ft_strdup(data->map.map[i]);
		if (!map_copy[i])
		{
			free_matrix(map_copy);
			free_exit_two(data, "Error\nMalloc error\n");
		}
	}
	map_copy[i] = NULL;
	flood_fill(data, data->player.x, data->player.y, map_copy);
	check_map_path_two(data, map_copy);
}
