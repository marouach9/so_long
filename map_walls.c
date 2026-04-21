#include "so_long.h"

int	is_walled_horizontal(t_game *game)
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
	return (1);
}

static int	is_walled_vertical(t_game *game)
{
	int	i;

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

int	is_walled(t_game *game)
{
	if (!is_walled_horizontal(game))
		return (0);
	if (!is_walled_vertical(game))
		return (0);
	return (1);
}