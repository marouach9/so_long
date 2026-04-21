#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx/mlx.h"

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		player;
	int		exit;
	int		collectible;
	int		moves;
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;
	int		player_x;
	int		player_y;
}	t_game;

/* file_reader.c */
char	*read_file(char *filename);

/* map_parser.c */
int		count_lines(char *str);
char	**split_lines(char *str);

/* map_utils.c */
int		get_height(char **map);
int		get_width(char *line);
int		is_rectangular(t_game *game);

/* map_walls.c */
int		is_walled(t_game *game);

/* map_elements.c */
int		check_elements(t_game *game);
void	validate_map(t_game *game);

/* map_path.c */
void	find_player(t_game *game, int *x, int *y);
void	flood_fill(char **map, int x, int y, int *exit_found);
int		check_path(char **map);
char	**copy_map(char **map);
void	validate_path(t_game *game);

/* render.c */
void	load_textures(t_game *game);
void	render_map(t_game *game);

/* player_move.c */
int		key_hook(int keycode, t_game *game);

/* main.c */
int		check_extension(char *filename);
int		close_window(t_game *game);

/* utils.c */
void	error(char *msg);
int		ft_strlen(char *str);
char	*ft_strdup(char *s);

#endif