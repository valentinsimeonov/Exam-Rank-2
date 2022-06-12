/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/

#include <unistd.h>


int		main(int argc, char **argv)
{
	int		i;
	int		j;
	int		flag[1000];

	i = 0;
	while (i <= 1000)
	{
		flag[i] = 0;
		i++;
	}
	i = 1;
	if (argc == 3)
	{
		while (i < 3)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				if (!flag[(unsigned char)argv[i][j]])
				{
					write(1, &argv[i][j], 1);
					flag[(unsigned char)argv[i][j]] = 1;
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
