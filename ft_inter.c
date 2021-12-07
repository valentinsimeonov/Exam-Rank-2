#include <unistd.h>

char	*ft_strchr(char *s, char c)
{
	while (*s != c)
	{
		if (*s == 0)
			return (0);
		s++;
	}
	return (s);
}

int	has_dup(char *s, char c, int len)
{
	while (s[--len])
		if (s[len] == c)
			return (1);
	return (0);
}

// int	main(int argc, char **argv)
int	main(int argc, char **argv)
{
	if (argc != 3)
		write(1, "\n", 1);
	else
	{
		char	*s1;
		char	*s2;
		int	i;

		s1 = argv[1];
		s2 = argv[2];
		// s1 = "argv[1]";
		// s2 = "argv[2]";

		i = 0;
		while (s1[i])
		{
			if (!has_dup(s1, s1[i], i) && ft_strchr(s2, s1[i]))
				write(1, &s1[i], 1);
			++i;
		}
		write(1, "\n", 1);
		return (0);
	}
}