#include "so_long.h"

static void	collect_item(t_game *game, int new_x, int new_y)
{
	game->collectible--;
	game->map[new_y][new_x] = '0';
}

static int	check_exit(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] != 'E')
		return (0);
	if (game->collectible > 0)
		return (1);
	game->moves++;
	printf("Moves: %d\n", game->moves);
	exit(0);
}

static void	update_position(t_game *game, int new_x, int new_y)
{
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_y][new_x] = 'P';
	game->moves++;
	printf("Moves: %d\n", game->moves);
	render_map(game);
}

static void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'C')
		collect_item(game, new_x, new_y);
	if (check_exit(game, new_x, new_y))
		return ;
	update_position(game, new_x, new_y);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 119 || keycode == 65362)
		move_player(game, 0, -1);
	if (keycode == 115 || keycode == 65364)
		move_player(game, 0, 1);
	if (keycode == 97 || keycode == 65361)
		move_player(game, -1, 0);
	if (keycode == 100 || keycode == 65363)
		move_player(game, 1, 0);
	return (0);
}