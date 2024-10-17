/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:59:14 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/10/14 11:59:15 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	get_map_size(t_data *data, char *map)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		message_error(data, "Error\nCould not open file %s\n", -1);
	line = get_next_line(fd);
	if (!line)
		message_error(data, "Error\nget_next_line error\n", fd);
	data->map.w = (ft_strlen(line) - 1);
	height = 0;
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	data->map.h = height;
	close(fd);
}

void	create_map_matrix(t_data *data, char *map)
{
	int	i;
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		message_error(data, "Error\nCould not open file %s\n", -1);
	data->map.map = (char **)malloc((sizeof(char *) * (data->map.h + 1)));
	if (!data->map.map)
		message_error(data, "Error\nMalloc error\n", fd);
	i = -1;
	while (++i < data->map.h)
	{
		data->map.map[i] = get_next_line(fd);
		if (!data->map.map[i])
			message_error(data, "Error\nMalloc error\n", fd);
	}
	data->map.map[i] = NULL;
	close(fd);
}

void	delete_newline_char(t_data *data)
{
	int	h;
	int	len;

	h = 0;
	while (data->map.map[h])
	{
		len = (int)ft_strlen(data->map.map[h]);
		if (data->map.map[h][len - 1] == '\n')
			data->map.map[h][len - 1] = '\0';
		h++;
	}
}

void	item_count(t_data *data)
{
	int	h;
	int	w;

	h = 0;
	while (data->map.map[h])
	{
		w = 0;
		while (data->map.map[h][w])
		{
			if (data->map.map[h][w] == 'P')
				data->map.player_count++;
			else if (data->map.map[h][w] == '0')
				data->map.fspace_count++;
			else if (data->map.map[h][w] == 'C')
				data->map.coin_count++;
			else if (data->map.map[h][w] == 'E')
				data->map.exit_count++;
			else if (data->map.map[h][w] == 'X')
				data->map.enemy_count++;
			w++;
		}
		h++;
	}
}

void	get_map_info(t_data *data, char *map)
{
	get_map_size(data, map);
	create_map_matrix(data, map);
	delete_newline_char(data);
	item_count(data);
	get_pos(data);
	get_pos_enemies(data);
}
