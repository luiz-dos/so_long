/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:59:21 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/10/16 12:06:15 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	close_window(t_data *data)
{
	free_exit(data, NULL);
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (data->game_over)
		return (0);
	if (keycode == XK_Escape)
		free_exit(data, NULL);
	else if (keycode == XK_w || keycode == XK_Up)
		move_player(data, data->player.x, (data->player.y - 1),
			data->player.direction);
	else if (keycode == XK_s || keycode == XK_Down)
		move_player(data, data->player.x, (data->player.y + 1),
			data->player.direction);
	else if (keycode == XK_a || keycode == XK_Left)
		move_player(data, (data->player.x - 1), data->player.y, LEFT);
	else if (keycode == XK_d || keycode == XK_Right)
		move_player(data, (data->player.x + 1), data->player.y, RIGHT);
	return (0);
}
