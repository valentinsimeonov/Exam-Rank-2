/*

Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$
*/

#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1); 
}

int		main(int argc, char **argv)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (argc == 2)
	{
		count = ft_strlen(argv[1]);
		while(count)
		{
			ft_putchar(argv[1][count - 1]);
			count--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
