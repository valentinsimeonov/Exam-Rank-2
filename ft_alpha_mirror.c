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

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	int		num;
	int		dif;
	char	output;

	i = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'M')
			{
				dif = 77 - argv[1][i];
				output = 78 + dif;
				write(1, &output, 1);
			}
			if (argv[1][i] >= 'N' && argv[1][i] <= 'Z')
			{
				dif = argv[1][i] - 78;
				output = 77 - dif;
				write(1, &output, 1);
			}

		}
		else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'm')
			{
				dif = 109 - argv[1][i];
				output = 110 + dif;
				write(1, &output, 1);
			}
			if (argv[1][i] >= 'n' && argv[1][i] <= 'z')
			{
				dif = argv[1][i] - 110;
				output = 109 - dif;
				write(1, &output, 1);
			}
		}
		else if (!(argv[1][i] >= 'A' && argv[1][i] <= 'Z') || !(argv[1][i] >= 'a' && argv[1][i] <= 'z'))
		{
			write(1, &argv[1][i], 1);
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}