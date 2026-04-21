#include "so_long.h"

static int	check_char(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'P')
		game->player++;
	else if (game->map[i][j] == 'E')
		game->exit++;
	else if (game->map[i][j] == 'C')
		game->collectible++;
	else if (game->map[i][j] != '0' && game->map[i][j] != '1')
		return (0);
	return (1);
}

static int	check_row(t_game *game, int i)
{
	int	j;

	j = 0;
	while (game->map[i][j])
	{
		if (!check_char(game, i, j))
			return (0);
		j++;
	}
	return (1);
}

static int	check_counts(t_game *game)
{
	if (game->player != 1 || game->exit != 1 || game->collectible < 1)
		return (0);
	return (1);
}

int	check_elements(t_game *game)
{
	int	i;

	i = 0;
	game->player = 0;
	game->exit = 0;
	game->collectible = 0;
	while (game->map[i])
	{
		if (!check_row(game, i))
			return (0);
		i++;
	}
	return (check_counts(game));
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