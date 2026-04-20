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

int	main(int argc, char **argv)
{
	t_game	game;
	char	*file;

	if (argc != 2)
		error("Usage: ./so_long map.ber");
	if (!check_extension(argv[1]))
		error("Map must be a .ber file");
	file = read_file(argv[1]);
	if (!file)
		error("Cannot read file");
	game.map = split_lines(file);
	free(file);
	validate_map(&game);
	validate_path(&game);
	game.moves = 0;
	game.mlx = mlx_init();
	if (!game.mlx)
		error("MLX init failed");
	game.win = mlx_new_window(game.mlx, game.width * 32,
			game.height * 32, "so_long");
	if (!game.win)
		error("Window creation failed");
	load_textures(&game);
	find_player(&game, &game.player_x, &game.player_y);
	render_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}