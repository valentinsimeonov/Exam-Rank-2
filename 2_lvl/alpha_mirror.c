/*
Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the number of arguments is not 1, display only a newline.

Examples:

$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>
*/

// 90 - 65 = 25

// A = 65 a = 97
// M = 77 m = 109

// N = 78 n = 110
// Z = 90 z =  122

// 77 - 65 = 12 rest    109 - letter
// 78 + 12 = 90 final letter  110 + rest

// 90 - 78 = 12 rest   122 - letter
// 77 - 12 = final letter 109 - rest

// letter - 65 = rest
// final_letter = howmuch + 78

#include <unistd.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int		i;
	int		rest;
	int		final_letter;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if(!((argv[1][i] >= 'A' && argv[1][i] <= 'Z') || (argv[1][i] >= 'a' && argv[1][i] <= 'z')))
			{
				write(1, &argv[1][i], 1);
			}

			else if (argv[1][i] >= 'A' && argv[1][i] <= 'M')
				{
					rest = 77 - argv[1][i];
					final_letter = 78 + rest;
					write(1, &final_letter, 1);
				}
			else if (argv[1][i] >= 'N' && argv[1][i] <= 'Z')
				{
					rest = argv[1][i] - 78;
					final_letter = 77 - rest;
					write(1, &final_letter, 1);
				}
			else if (argv[1][i] >= 'a' && argv[1][i] <= 'm')
				{
					rest = 109 - argv[1][i];
					final_letter = 110 + rest;
					write(1, &final_letter, 1);

				}
			else if (argv[1][i] >= 'n' && argv[1][i] <= 'z')
				{
					rest = argv[1][i] - 110;
					final_letter = 109 - rest;
					write(1, &final_letter, 1);
				}
			i++;
		}
		
	}
	write(1, "\n", 1);
	return (0);
}
