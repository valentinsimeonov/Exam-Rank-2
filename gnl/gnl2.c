char	*get_next_line(int fd)
{
	int		read_count;
	char	*buf;
	char	character;
	int		i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = malloc(10000);
	read_count = read(fd, &character, 1);
	while (read_count > 0)
	{
		buf[i] = character;
		i++;
		if (c  == '\n')
			return(buf);
		read_count = read(fd, &character, 1);
	}
	if (read_count == -1)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}

int		main()
{
	int		fd;
	char	*str;
	fd = open("myfile.txt", O_RDONLY);
	str = get_next_line(fd);
	free(str);
	while (str != 0)
	{
		printf("%s", str);
		str = get_next_line(fd);
		free(str);
	}
	close(fd);
	return (0);
}