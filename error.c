/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:59:05 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/10/14 11:59:06 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	message_error(t_data *data, char *message, int fd)
{
	if (data->map.map)
		free_matrix(data->map.map);
	if (message)
		ft_printf("%s", message);
	if (fd >= 0)
		close(fd);
	exit(1);
}

void	map_error(t_data *data, char *message)
{
	free_matrix(data->map.map);
	if (data->enemies)
		free(data->enemies);
	if (message)
		ft_printf("%s", message);
	exit(1);
}
