/*

   
Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);
*/

#include <unistd.h>
#include <stdio.h>

 /* Thanks Tim */
int	    is_power_of_2(unsigned int n)
{
	unsigned int i;

	i = 0;
	if (n < 0)
		return (0);
	while (i < n)
	{
		if (i * i == n)
			return (1);
		i++;
	}
	return (0);
}

int	main()
{
	int		num;

	num = 5;
	printf("%d\n", is_power_of_2(num));
	return (0);
}
