#include "so_long.h"

char	*read_file(char *filename)
{
	int		fd;
	char	*buffer;
	int		bytes;

	buffer = malloc(10000);
	if (!buffer)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(buffer);
		return (NULL);
	}
	bytes = read(fd, buffer, 9999);
	if (bytes < 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes] = '\0';
	close(fd);
	return (buffer);
}

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

char	**split_lines(char *str)
{
	char	**map;
	int		i;
	int		j;
	int		k;
	int		len;

	i = 0;
	j = 0;
	map = malloc(sizeof(char *) * (count_lines(str) + 1));
	if (!map)
		return (NULL);
	while (str[i])
	{
		k = 0;
		len = 0;
		while (str[i + len] && str[i + len] != '\n')
			len++;
		if (len == 0)
		{
			if (str[i] == '\n')
				i++;
		}
        else
		{
            map[j] = malloc(sizeof(char) * (len + 1));
            if (!map[j])
                return (NULL);
            while (str[i] && str[i] != '\n')
			    map[j][k++] = str[i++];
		    map[j][k] = '\0';
		    j++;
		    if (str[i] == '\n')
			    i++;
	}
}
	map[j] = NULL;
	return (map);
}