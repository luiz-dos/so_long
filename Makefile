NAME	= so_long
LIB		= so_long.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I../include
RM		= rm -f
CREATE	= ar rcs
LIBFT	= libft
MLX		= minilibx-linux
MLX_URL = https://cdn.intra.42.fr/document/document/27192/minilibx-linux.tgz
SRCS	= check_map.c create_map.c destroy_images.c end_screen.c error.c flood_fill.c \
			free_exit.c get_map_info.c key_press.c load_game.c move_enemies.c moves.c \
			so_long.c update_game.c utils.c 
OBJS	= ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${MLX} ${LIB} 
	make -C ${LIBFT}
	${CC} ${CFLAGS} ${OBJS} -L./${LIBFT} -L./${MLX} -lft -lmlx_Linux -lXext -lX11 -o $@

${LIB}: ${OBJS}
	${CREATE} ${LIB} $^

${MLX}:
	wget ${MLX_URL} -O minilibx-linux.tgz
	tar -xvzf minilibx-linux.tgz
	${RM} minilibx-linux.tgz
	make -C ${MLX}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	make clean -C ${LIBFT}
	${RM} ${OBJS}

fclean: clean
	make fclean -C ${LIBFT}
	${RM} ${LIB}
	${RM} ${NAME}
	rm -rf ${MLX}

re: fclean all

.PHONY: all clean fclean re