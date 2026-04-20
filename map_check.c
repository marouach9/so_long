#include "so_long.h"

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	get_width(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

int	is_rectangular(t_game *game)
{
	int	i;

	i = 0;
	game->width = get_width(game->map[0]);
	while (game->map[i])
	{
		if (get_width(game->map[i]) != game->width)
			return (0);
		i++;
	}
	game->height = i;
	return (1);
}

int	is_walled(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1'
			|| game->map[game->height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1'
			|| game->map[i][game->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->player = 0;
	game->exit = 0;
	game->collectible = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				game->player++;
			else if (game->map[i][j] == 'E')
				game->exit++;
			else if (game->map[i][j] == 'C')
				game->collectible++;
			else if (game->map[i][j] != '0'
				&& game->map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	if (game->player != 1 || game->exit != 1
		|| game->collectible < 1)
		return (0);
	return (1);
}

void	validate_map(t_game *game)
{
	if (!is_rectangular(game))
		error("Map not rectangular");
	if (!is_walled(game))
		error("Map not closed by walls");
	if (!check_elements(game))
		error("Invalid elements");
}