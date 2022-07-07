/*
Assignment name  : ulstr
Expected files   : ulstr.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and reverses the case of all its letters.
Other characters remain unchanged.

You must display the result followed by a '\n'.

If the number of arguments is not 1, the program displays '\n'.

Examples :

$>./ulstr "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-justification." | cat -e
l'EspRIT Ne PEuT PLuS PrOGrESsER S'iL STAgNE ET Si PErSiStENT vaNiTE ET AUTO-JUSTIFICATION.$
$>./ulstr "S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  " | cat -e
"S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  " | cat -e$
$>./ulstr "3:21 Ba  tOut  moUn ki Ka di KE m'en Ka fe fot" | cat -e
3:21 bA  ToUT  MOuN KI kA DI ke M'EN kA FE FOT$
$>./ulstr | cat -e
$

*/

// 97 - 65 = 32

// Passed Moulinette 07.07.2022


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		i;
	char	letter;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if (!((argv[1][i] >= 'a' && argv[1][i] <= 'z') || (argv[1][i] >= 'A' && argv[1][i] <= 'Z')))
			{
				write(1, &argv[1][i], 1);
			}
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			{
				letter = argv[1][i] - 32;
				write(1, &letter, 1);
			}
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				letter = argv[1][i] + 32;
				write(1, &letter, 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
