/*
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>

*/

#include <unistd.h>
#include <stdio.h>

void	repeat_alpha(char *str)
{
	int		i;
	int		j;
	char	letter;
	int		times;

	i = 0;
	// if (!str[i])
	while (str[i] || str[i] != '\0')
	{
			/* Is Anything else */
		if ((str[i] < 97 && str[i] > 122) || (str[i] < 65 && str[i] > 90))
		{
			letter = str[i];
			write(1, &letter, 1);
		}
			/* Is Upper */
		if (str[i] >= 97 && str[i] <= 122)
		{
			j = 0;
			times = 0;
			letter = str[i];
			printf("%c", letter);
			times = letter - 96;
			printf("%d", times);
			while (j < times)
			{
				write(1, &letter, 1);
				j++;
			}
		}
			/* Is Lower */
		if (str[i] >= 65 && str[i] <= 90)
		{
			j = 0;
			times = 0;
			letter = str[i];
			printf("%c", letter);
			times = letter - 64;
			printf("%d", times);
			while (j < times)
			{
				write(1, &letter, 1);
				j++;
			}
		}

		i++;
	}
	write(1, "\n", 1);
}

int	main()
{
	char	*str;

	str = "abc 43 A";
	repeat_alpha(str);	
	return (0);
}

