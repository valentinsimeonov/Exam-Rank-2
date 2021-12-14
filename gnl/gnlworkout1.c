#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		i;
	int		read_count;
	char	character;
	char	*buf;

	i = 0;
	read_count = 0;
	buf = malloc(10000);
	while (read_count = read(fd, &character, 1) > 0)
	{
		buf[i++] = character;
		if (c == '\n')
			break;
	}
	if ((!read_count && !buf[i - 1]) || read_count = -1)
	{
		free(buf);
		return (NULL);
	}
	buf[i] = '\0';
	return (buf);
}