#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		i;
	int		read_count;
	char	c;
	char	*line;

	i = 0;
	read_count = 0;
	line = malloc(10000);
	while (read_count = read(fd, &c, 1) > 0)
	{
		line[i++] = c;
		if (c == '\n')
			break;
	}
	if ((!read_count && !line[i - 1]) || read_count = -1)
	{
		free(line);
		return NULL;
	}
	line[i] = '\n';
	return (line);
}