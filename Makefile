NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I ./gnl -I ./printf -I ./printf/libft
SRCS = characters.c check_position_validity.c elements.c elements_check.c  \
file_error.c image.c line_read.c  \
main.c map_checking.c map_error.c map_read.c  \
so_long.c terrain.c walls_check.c window.c  \
window_error.c key_functions.c ft_char_to_enum.c elements_identify.c key_functions2.c\
moves.c free_functions.c move_fire.c next_wall.c
LIBFT = ./printf/libft/libft.a
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = ./printf/libft/

LIBMLX = ./MLX42

all: gnl libft printf libmlx $(NAME)

$(NAME): $(OBJS)
	$(CC) -Ofast -march=nocona -flto $(INCLUDE) $(OBJS) -L$(LIBMLX) -L./gnl/ -lgnl -L./printf/ -lftprintf -L./printf/libft -lft -lmlx42 -L "$(shell brew --prefix glfw)/lib/" -lglfw  -o $(NAME)

libmlx:
	${MAKE} -C $(LIBMLX)

libft:
	${MAKE} -C $(LIBFT_DIR)

printf:
	${MAKE} -C ./printf

gnl:
	${MAKE} -C ./gnl/

clean:
	@rm -f $(OBJS)
	@${MAKE} clean -C $(LIBMLX)
	@${MAKE} clean -C ./printf/
	@${MAKE} clean -C ./gnl/

fclean: clean
	@rm -f $(NAME)
	@${MAKE} -C $(LIBMLX) fclean
	@${MAKE} -C ./printf/ fclean
	@${MAKE} -C ./gnl/ fclean

re: fclean all

.PHONY: all re fclean clean gnl libft printf