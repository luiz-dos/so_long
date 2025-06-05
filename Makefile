NAME	= so_long
LIB		= so_long.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I../include
RM		= rm -f
CREATE	= ar rcs
LIBFT	= libft
MLX		= minilibx-linux
SRCS	= check_map.c create_map.c destroy_images.c end_screen.c error.c flood_fill.c \
			free_exit.c get_map_info.c key_press.c load_game.c move_enemies.c moves.c \
			so_long.c update_game.c utils.c 
OBJS	= ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${MLX} ${LIB} 
	make -C ${LIBFT}
	make -C ${MLX}
	${CC} ${CFLAGS} ${OBJS} -L./${LIBFT} -L./${MLX} -lft -lmlx_Linux -lXext -lX11 -o $@

${LIB}: ${OBJS}
	${CREATE} ${LIB} $^

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	make clean -C ${LIBFT}
	${RM} ${OBJS}

fclean: clean
	make fclean -C ${LIBFT}
	${RM} ${LIB}
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re