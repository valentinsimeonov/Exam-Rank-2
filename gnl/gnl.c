#include "get_next_line.h"

char *get_next_line(int fd)
{
	int read_count;
	int	i;
	char c;
	char	*line;

	i = 0; 
	read_count = 0;
	line = malloc(10000);
	while ((read_count = read(fd, &c, 1) > 0))
	{
		line[i++] = c;
		if (c == '\n')  
			break; 
	} 
	if ((!read_count && !line[i - 1]) || read_count == -1)
	{     
		free(line);
		return NULL;
	}     
	line[i] = '\0';
	return (line); 
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