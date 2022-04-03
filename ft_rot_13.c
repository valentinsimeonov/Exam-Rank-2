/*
Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>
*/

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		num;
	int		dif;
	int		output;

	i = 0;
	if (argc != 2)
		{
		write(1, "\n", 1);
		return (0);
		}
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			{
			if (argv[1][i] + 13 > 122)
				{
				num = argv[1][i] + 13;
				dif = num - 122;
				output = 96 + dif;
				ft_putchar(output);
				}
			else
				ft_putchar(argv[1][i] + 13);
			}
		else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
			if (argv[1][i] + 13 > 90)
				{
				num = argv[1][i] + 13;
				dif = num - 90;
				output = 64 + dif;
				ft_putchar(output);
				}
			else
				ft_putchar(argv[1][i] + 13);
			}
		else if (!(argv[1][i] >= 'a' && argv[1][i] <= 'z') || !(argv[1][i] >= 'A' && argv[1][i] <= 'Z'))
			ft_putchar(argv[1][i]);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
