#include "so_long.h"

int	check_extension(char *filename)
{
	int	len;

	len = 0;
	while (filename[len])
		len++;
	if (len < 4)
		return (0);
	return (filename[len - 4] == '.' && filename[len - 3] == 'b'
		&& filename[len - 2] == 'e' && filename[len - 1] == 'r');
}

int	close_window(t_game *game)
{
	(void)game;
	exit(0);
}

static void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error("MLX init failed");
	game->win = mlx_new_window(game->mlx, game->width * 64,
			game->height * 64, "so_long");
	if (!game->win)
		error("Window creation failed");
}

static void	init_map(t_game *game, char *filename)
{
	char	*file;

	file = read_file(filename);
	if (!file)
		error("Cannot read file");
	game->map = split_lines(file);
	free(file);
	validate_map(game);
	validate_path(game);
	game->moves = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error("Usage: ./so_long map.ber");
	if (!check_extension(argv[1]))
		error("Map must be a .ber file");
	init_map(&game, argv[1]);
	init_mlx(&game);
	load_textures(&game);
	find_player(&game, &game.player_x, &game.player_y);
	render_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}