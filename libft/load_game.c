/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:59:18 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/10/16 12:43:59 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

t_img	load_image(t_data *data, char *path)
{
	t_img	img;

	img.iptr = mlx_xpm_file_to_image(data->mlx, path, &img.x, &img.y);
	if (img.iptr == NULL)
		free_exit(data, "Error loading image");
	return (img);
}

void	load_map_images(t_data *data)
{
	data->map_img[0] = load_image(data, "img/grass.xpm");
	data->map_img[1] = load_image(data, "img/wall.xpm");
	data->map_img[2] = load_image(data, "img/coin.xpm");
	data->map_img[3] = load_image(data, "img/cdoor.xpm");
	data->map_img[4] = load_image(data, "img/odoor.xpm");
	data->end_screen[0] = load_image(data, "img/you_win.xpm");
	data->end_screen[1] = load_image(data, "img/game_over.xpm");
	data->left[0] = load_image(data, "img/l1.xpm");
	data->left[1] = load_image(data, "img/l2.xpm");
	data->left[2] = load_image(data, "img/l3.xpm");
	data->left[3] = load_image(data, "img/l4.xpm");
	data->left[4] = load_image(data, "img/l5.xpm");
	data->left[5] = load_image(data, "img/l6.xpm");
	data->right[0] = load_image(data, "img/r1.xpm");
	data->right[1] = load_image(data, "img/r2.xpm");
	data->right[2] = load_image(data, "img/r3.xpm");
	data->right[3] = load_image(data, "img/r4.xpm");
	data->right[4] = load_image(data, "img/r5.xpm");
	data->right[5] = load_image(data, "img/r6.xpm");
	data->enemy[0] = load_image(data, "img/enemy.xpm");
	data->enemy[1] = load_image(data, "img/enemy1.xpm");
	data->enemy[2] = load_image(data, "img/enemy.xpm");
	data->enemy[3] = load_image(data, "img/enemy1.xpm");
	data->enemy[4] = load_image(data, "img/enemysad.xpm");
	data->enemy[5] = load_image(data, "img/enemyhappy.xpm");
}

void	load_number_images(t_data *data)
{
	data->nbr[0] = load_image(data, "img/zero.xpm");
	data->nbr[1] = load_image(data, "img/one.xpm");
	data->nbr[2] = load_image(data, "img/two.xpm");
	data->nbr[3] = load_image(data, "img/three.xpm");
	data->nbr[4] = load_image(data, "img/four.xpm");
	data->nbr[5] = load_image(data, "img/five.xpm");
	data->nbr[6] = load_image(data, "img/six.xpm");
	data->nbr[7] = load_image(data, "img/seven.xpm");
	data->nbr[8] = load_image(data, "img/eight.xpm");
	data->nbr[9] = load_image(data, "img/nine.xpm");
}

void	load_game(t_data *data)
{
	load_map_images(data);
	load_number_images(data);
	data->map.enemy_move_delay = 11000;
	data->player.frame_delay = 1000;
	create_map(data);
	load_move_counter(data);
}
