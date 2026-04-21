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