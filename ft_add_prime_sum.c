/*

Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

#include <unistd.h>

// int	*generate_prime(int num)
// {
// 	int		i;
// 	int		j;
// 	int		array[10000];

// 	i = 0;
// 	while(i < 100000000)
// 	{
// 		if (num / i == 1 && num % i == 0)
// 			array[j] = num;
// 		i++;
// 		j++;
// 	}
// 	return (array);
// }

int		is_int_is_positive(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9') || str[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

int		ft_atoi(char *str)
{
	int	i;
	int sign;
	int num;

	i = 0;
	sign = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return(sign * num);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		num;
	int		prime;
	int		array[100] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

	i = 0;
	j = 0;
	prime = 0;
	if (!is_int_is_positive(argv[1]))
	{
		write(1, "\n", 1);
		return (0);
	}
	while(i < 100000000)
	{
		if (prime / i == 1 && prime % i == 0)
			array[j] = prime;
		i++;
		j++;
	}
	i = 0;
	j = 0;
	num = ft_atoi(argv[1]);
	if (argc == 2)
	{
		if (array[j] == num)
		{
			while (array[i] <= array[j])
			{
				write(1, &array[i], 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
