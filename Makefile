CFLAGS = -Wall -Wextra -Werror
MLX_PATH = mlx/
MLX = $(MLX_PATH)libmlx.a
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm

NAME = so_long

SRCS = so_long.c \
	map.c \
	map_check.c \
	path.c \
	utils.c \
	render.c \
	move.c

OBJS = $(SRCS:.c=.o)
INC = so_long.h

all: $(MLX) $(NAME)

$(MLX):
	make -C $(MLX_PATH) 2>/dev/null; true

%.o: %.c $(INC)
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	cc $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(MLX_PATH) clean 2>/dev/null; true

fclean: clean
	rm -f $(NAME)

re: fclean all