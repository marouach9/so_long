#include "so_long.h"

void	load_textures(t_game *game)
{
	int	w;
	int	h;

	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &w, &h);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &w, &h);
	if (!game->img_wall || !game->img_floor || !game->img_player
		|| !game->img_collectible || !game->img_exit)
		error("Failed to load textures");
}

void	render_map(t_game *game)
{
	int		i;
	int		j;
	void	*img;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == '1')
				img = game->img_wall;
			else if (game->map[i][j] == 'C')
				img = game->img_collectible;
			else if (game->map[i][j] == 'E')
				img = game->img_exit;
			else if (game->map[i][j] == 'P')
				img = game->img_player;
			else
				img = game->img_floor;
			mlx_put_image_to_window(game->mlx, game->win,
				img, j * 32, i * 32);
			j++;
		}
		i++;
	}
}