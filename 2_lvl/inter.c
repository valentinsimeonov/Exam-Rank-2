/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/

#include <stdlib.h>
#include <unistd.h>

int		main(int argc, char **argv)
{
	int 	i;
	int		j;
	int		flag[1000];

	i = 0;
	while (i <= 1000)
	{
		flag[i] = 0;
		i++;
	}
	i = 2;
	if (argc == 3)
	{
		while (i > 0)
		{
			j = 0;
			while (argv[i][j])
			{
				if (i == 2 && !flag[(unsigned char)argv[i][j]])
					flag[(unsigned char)argv[i][j]] = 1;
				else if (i == 1 && flag[(unsigned char)argv[i][j]] == 1)
				{
					write(1, &argv[i][j], 1);
					flag[(unsigned char)argv[i][j]] = 2;
				}
				j++;
			}
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
