/*
Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);
*/

#include <unistd.h>
#include <stdio.h>


void	ft_swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		main()
{
	int		*a;
	int		*b;
	int		val1;
	int		val2;

	val1 = 7;
	val2 = 23;

	a = &val1;
	b = &val2;


	printf("%d\n", *a);
	printf("%d\n", *b);
	ft_swap(a, b);
	printf("Swapped\n");
	printf("%d\n", *a);
	printf("%d\n", *b);

	return(0);
}
