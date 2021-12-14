#include <unistd.h>

int	has_dup(char *s, char c, int len)
{
	while (s[--len])
		if (s[len] == c)
			return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		write(1, "\n", 1);
	else
	{
		char	*s1;
		char	*s2;
		int	i;
		int	j;

		i = 0;
		j = 0;
		s1 = argv[1];
		s2 = argv[2];
		while (s1[i])
		{
			if (!has_dup(s1, s1[i], i + 1))
				write(1, &s1[i], 1);
			i++;
		}
		while (s2[j])
		{
			if (!has_dup(s1, s2[j], i) && !has_dup(s2, s2[j], j))
				write(1, &s2[j], 1);
			j++;
		}
		write(1, "\n", 1);
	}
	return (0);
}