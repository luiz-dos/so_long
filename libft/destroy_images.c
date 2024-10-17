/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:58:54 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/10/14 13:36:53 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	destroy_images(t_data *data)
{
	int	i;

	i = -1;
	while (++i <= 4 && data->map_img[i].iptr != NULL)
		mlx_destroy_image(data->mlx, data->map_img[i].iptr);
	i = -1;
	while (++i <= 5 && data->left[i].iptr != NULL)
		mlx_destroy_image(data->mlx, data->left[i].iptr);
	i = -1;
	while (++i <= 5 && data->right[i].iptr != NULL)
		mlx_destroy_image(data->mlx, data->right[i].iptr);
	i = -1;
	while (++i <= 5 && data->enemy[i].iptr != NULL)
		mlx_destroy_image(data->mlx, data->enemy[i].iptr);
	i = -1;
	while (++i <= 1 && data->end_screen[i].iptr != NULL)
		mlx_destroy_image(data->mlx, data->end_screen[i].iptr);
	i = -1;
	while (++i <= 9 && data->nbr[i].iptr != NULL)
		mlx_destroy_image(data->mlx, data->nbr[i].iptr);
}
