/*
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);
*/

// Passed Moulinette on 21.06.2022

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char    *ft_strrev(char *str)
{
	int		i;
	char	temp;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		temp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = temp;
		i++;
		len--;
	}
	return (str);
}

int		main()
{
	char	str[] = "abc";

	printf("%s", ft_strrev(str));
}
