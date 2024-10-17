/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:00:01 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/10/16 12:06:15 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "libft.h"
# include <X11/keysym.h>

/* block_size */
# define BSIZE 64

/* directions*/
# define RIGHT 0
# define LEFT 1

typedef struct s_img
{
	void		*iptr;
	int			x;
	int			y;
}				t_img;

typedef struct s_map
{
	char		**map;
	int			w;
	int			h;
	int			player_count;
	int			fspace_count;
	int			coin_count;
	int			exit_count;
	int			enemy_count;
	int			door_status;
	int			counter_pos;
	int			enemy_move_time;
	int			enemy_move_delay;
	int			enemy_direction;
	int			end_screen_time;
}				t_map;

typedef struct s_player
{
	int			x;
	int			y;
	int			nmoves;
	int			hundreds;
	int			tens;
	int			units;
	int			frame_time;
	int			current_frame;
	int			frame_delay;
	int			direction;
}				t_player;

typedef struct s_door
{
	int			x;
	int			y;
	int			in_door;
}				t_door;

typedef struct s_enemy
{
	int			x;
	int			y;
}				t_enemy;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			game_over;
	int			result;
	t_player	player;
	t_door		door_pos;
	t_map		map;
	t_enemy		*enemies;
	t_img		map_img[5];
	t_img		left[6];
	t_img		right[6];
	t_img		enemy[6];
	t_img		end_screen[2];
	t_img		nbr[10];
}				t_data;

/* read and get map information */
void			initial_check(t_data *data, char *map);
void			check_map_existence(char *file_name);
void			get_map_info(t_data *data, char *map);
void			get_map_size(t_data *data, char *map);

/* create a map matrix and count the items */
void			create_map_matrix(t_data *data, char *map);
void			delete_newline_char(t_data *data);
void			item_count(t_data *data);
void			get_pos(t_data *data);
void			get_pos_enemies(t_data *data);

/* check if the map is valid */
void			check_map(t_data *data);
void			check_format(t_data *data);
void			check_walls(t_data *data);
void			check_map_composition(t_data *data);
void			map_is_valid(t_data *data);

/* check if there is a valid path on the map */
void			check_map_path(t_data *data);
void			check_map_path_two(t_data *data, char **map_copy);
void			flood_fill(t_data *data, int x, int y, char **visited);

/* load map images */
void			load_game(t_data *data);
t_img			load_image(t_data *data, char *path);
void			load_map_images(t_data *data);
void			load_number_images(t_data *data);

/* create the map and position the move counter*/
void			create_map(t_data *data);
void			select_block(t_data *data, int h, int w, char c);
void			load_move_counter(t_data *data);

/* enemy movement */
void			update_enemies(t_data *data);
void			move_enemies(t_data *data);
void			choose_a_move(t_data *data, int index);
void			basic_enemy_move(t_data *data, int index, int new_x, int new_y);

/* player movement */
int				key_press(int keycode, t_data *data);
void			move_player(t_data *data, int new_x, int new_y, int direction);
void			move(t_data *data, int new_x, int new_y, char block);
void			basic_move(t_data *data, int new_x, int new_y);
void			number_of_moves(t_data *data);
void			move_direction(t_data *data, int x, int y);
void			update_player_animation(t_data *data);
int				update_game(t_data *data);

/* end game images */
void			end_screen(t_data *data, int image);
void			update_enemy_images(t_data *data, int image);
int				wait_and_exit(t_data *data);

/* handle errors and close window */
int				close_window(t_data *data);
void			free_exit(t_data *data, char *message);
void			free_exit_two(t_data *data, char *message);
void			free_matrix(char **matrix);
void			map_error(t_data *data, char *message);
void			message_error(t_data *data, char *message, int fd);
void			destroy_images(t_data *data);

#endif /* SO_LONG_H */
