#include "so_long.h"

void	find_player(t_game *game, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(char **map, int x, int y, int *exit_found)
{
	int	width;
	int	height;

	height = 0;
	while (map[height])
		height++;
	width = ft_strlen(map[0]);
	if (x < 0 || y < 0 || y >= height || x >= width)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'E')
	{
		*exit_found = 1;
		return ;
	}
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, exit_found);
	flood_fill(map, x - 1, y, exit_found);
	flood_fill(map, x, y + 1, exit_found);
	flood_fill(map, x, y - 1, exit_found);
}

int	check_path(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**copy_map(char **map)
{
	int		i;
	char	**copy;

	i = 0;
	while (map[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	validate_path(t_game *game)
{
	char	**copy;
	int		x;
	int		y;
	int		exit_found;

	exit_found = 0;
	copy = copy_map(game->map);
	if (!copy)
		error("Malloc failed");
	find_player(game, &x, &y);
	flood_fill(copy, x, y, &exit_found);
	if (!exit_found || !check_path(copy))
		error("No valid path");
}