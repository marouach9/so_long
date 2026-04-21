#include "so_long.h"

int	count_lines(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count + 1);
}

static int	get_line_len(char *str, int i)
{
	int	len;

	len = 0;
	while (str[i + len] && str[i + len] != '\n')
		len++;
	return (len);
}

static int	fill_line(char **map, char *str, int i, int j)
{
	int	k;

	k = 0;
	map[j] = malloc(sizeof(char) * (get_line_len(str, i) + 1));
	if (!map[j])
		return (-1);
	while (str[i] && str[i] != '\n')
		map[j][k++] = str[i++];
	map[j][k] = '\0';
	return (i);
}

char	**split_lines(char *str)
{
	char	**map;
	int		i;
	int		j;

	map = malloc(sizeof(char *) * (count_lines(str) + 1));
	if (!map)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (get_line_len(str, i) == 0)
			i++;
		else
		{
			i = fill_line(map, str, i, j++);
			if (i < 0)
				return (NULL);
			if (str[i] == '\n')
				i++;
		}
	}
	map[j] = NULL;
	return (map);
}