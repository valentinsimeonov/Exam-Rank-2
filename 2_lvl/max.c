/*
Assignment name  : max
Expected files   : max.c
Allowed functions: 
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/

#include <stdio.h>

int		max(int* tab, unsigned int len)
{
	unsigned int	i;
	int				temp;

	if (!tab || !len)
		return (0);
	i = 0;
	while (i < len - 1)
	{
		if (tab[i] < tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = -1;
		}
		i++;
	}
	return (tab[0]);
}

int		main()
{
	int		tab[] = {};
	printf("%d", max(tab, 3));
	return (0);
}
