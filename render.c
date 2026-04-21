/* render.c */
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

static void	*get_tile_img(t_game *game, char tile)
{
	if (tile == '1')
		return (game->img_wall);
	if (tile == 'C')
		return (game->img_collectible);
	if (tile == 'E')
		return (game->img_exit);
	if (tile == 'P')
		return (game->img_player);
	return (game->img_floor);
}

void	render_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				get_tile_img(game, game->map[i][j]), j * 64, i * 64);
			j++;
		}
		i++;
	}
}