/*
Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

The output will be followed by a \n.

If the number of arguments is not 1, the program displays \n.

Example:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>
*/

#include <unistd.h>

/* I could have Made it Simpler, however I made just as ft_rot_13 so I can Understand Myself Better */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		num;
	int		dif;
	char	output;


	i = 0;
	if (argc !=  2)
	{
		write(1, "\n", 1);
		return(0);
	}
	while (argv[1][i] != '\0')
	{

				/* is Upper */
		if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
		{
			if (argv[1][i] + 1 > 90)
			{
				num = argv[1][i] + 1;
				dif = num - 90;
				output = 64 + dif;
				ft_putchar(output);
			}
			else
				ft_putchar(argv[1][i] + 1);
		}
				/* is Lower */
		else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
		{
			if (argv[1][i] + 1 > 122)
			{
				num = argv[1][i] + 1;
				dif = num - 122;
				output = 96 + dif;
				ft_putchar(output);
			}
			else
				ft_putchar(argv[1][i] + 1);
		}
		else if (!(argv[1][i] >= 'A' && argv[1][i] <= 'Z') || !(argv[1][i] >= 'a' && argv[1][i] <= 'z'))
		{
			ft_putchar(argv[1][i]);
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}