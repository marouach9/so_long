#include "so_long.h"

static int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

static char	*read_buffer(int fd)
{
	char	*buffer;
	int		bytes;

	buffer = malloc(10000);
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, 9999);
	if (bytes < 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes] = '\0';
	return (buffer);
}

char	*read_file(char *filename)
{
	int		fd;
	char	*buffer;

	fd = open_file(filename);
	if (fd < 0)
		return (NULL);
	buffer = read_buffer(fd);
	close(fd);
	return (buffer);
}