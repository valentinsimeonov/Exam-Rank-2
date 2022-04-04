/*
Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there's one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		i;
	int		num;
	int		prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43};

	i = 0;
	if (argc != 2)
	{
		printf("\n");
		return(0);
	}
	num = atoi(argv[1]);
	if (num == 1)
		printf("%d\n", 1);
	else
	{
		while (prime[i] != '\0')
		{
			if (num % prime[i] == 0)
			{
				printf("%d\n", prime[i]);
				if (num / prime[i] != 0)
					printf("*");
				num = num / prime[i];
				i = 0;
			}
			i++;
		}
	}
	return (0);
}
