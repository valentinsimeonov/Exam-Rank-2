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
	while ((read_count = read(fd, &character, 1) > 0))
	{
		buf[i++] = character;
		if (character == '\n')
			break;
	}
	if ((!read_count && !buf[i - 1]) || read_count == -1)
	{
		free(buf);
		return (NULL);
	}
	buf[i] = '\0';
	return(buf);
}

int		main()
{
	int		fd;
	char	*str;
	fd = open("myfile.txt", O_RDONLY);
	str = get_next_line(fd);
	// free(str);
	while (str != 0)
	{
		printf("%s", str);
		str = get_next_line(fd);
		free(str);
	}
	close(fd);
	return (0);
}