/*

Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$>
*/

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar (str[i]);
		i++;
	}
}

void	ft_putnbr(int num)
{
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		num = num % 10;
	}
	if (num < 10)
	{
		ft_putchar(num + '0');
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	*fizz;
	char	*buzz;
	char	*fizzbuzz;

	i = 1;

	buzz = "buzz";
	fizz = "fizz";
	fizzbuzz = "fizzbuzz";
	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			ft_putstr(fizzbuzz);
			write(1, "\n", 1);
		}
		else if (i % 3 == 0)
			{
			ft_putstr(fizz);
			write(1, "\n", 1);
			}
		else if (i % 5 == 0)
			{

			ft_putstr(buzz);
			write(1, "\n", 1);
			}
		else
		{
			ft_putnbr(i);
			write(1, "\n", 1);
		}
		i++;
	}
}
