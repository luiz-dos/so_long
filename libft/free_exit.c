/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:59:11 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/10/14 13:36:32 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

void	free_exit_two(t_data *data, char *message)
{
	free_matrix(data->map.map);
	if (data->enemies)
		free(data->enemies);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	ft_printf("%s", message);
	exit(1);
}

void	free_exit(t_data *data, char *message)
{
	destroy_images(data);
	if (message)
		ft_printf("%s\n", message);
	if (data->map.map)
		free_matrix(data->map.map);
	if (data->enemies)
		free(data->enemies);
	if (data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(1);
}
