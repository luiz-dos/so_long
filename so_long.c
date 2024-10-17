/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:59:36 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/10/17 11:24:23 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	initial_check(t_data *data, char *map)
{
	check_map_existence(map);
	get_map_info(data, map);
	check_map(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		ft_printf("Usage: ./so_long <map_file.ber>\n");
		return (1);
	}
	ft_bzero(&data, sizeof(data));
	initial_check(&data, av[1]);
	data.mlx = mlx_init();
	if (!data.mlx)
		free_exit_two(&data, "Error starting mlx\n");
	data.win = mlx_new_window(data.mlx, (data.map.w * BSIZE), (data.map.h
				* BSIZE), "./so_long");
	if (!data.win)
		free_exit_two(&data, "Error creating window\n");
	load_game(&data);
	mlx_loop_hook(data.mlx, update_game, &data);
	mlx_key_hook(data.win, key_press, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
