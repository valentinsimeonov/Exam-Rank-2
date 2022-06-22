/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/

#include <stdlib.h>
#include <stdio.h>

// int	*ft_range(int start, int end)
// {
// 	int	size;
// 	int	*ret;
// 	int	*ptr;
// 	// int	i;

// 	// i = 0;
// 	size = end - start;
// 	if (size)
// 	{
// 		ptr = (int *)malloc(sizeof(int) * size);
// 		if (ptr)
// 		{
// 			ret = ptr;
// 			while (start <= end)
// 			{
// 				*ptr = start;
// 				ptr++;
// 				start++;
// 			}
// 			return (ret);
// 		}
// 	}
// 	return (NULL);
// }

// int			main()
// {
// 	int		start;
// 	int		end;
// 	int		*arr;

// 	start = 0;
// 	end = 0;
// 	arr = ft_range(start, end);
// 	int	i = 0;
// 	while (start <= end)
// 	{
// 		printf("%i", arr[i]);
// 		start++;
// 		i++;
// 	}
// 	return (0);
// }



// int		ft_abs(int x)
// {
// 	if (x < 0)
// 		return (-x);
// 	return (x);
// }

// int		*ft_range(int start, int end)
// {
// 	int i;
// 	int *tab;

// 	i = 0;
// 	tab = (int*)malloc(sizeof(int) * ft_abs(start - end) + 1);
// 	while (start < end)
// 	{
// 		tab[i] = start;
// 		start++;
// 		i++;
// 	}
// 	tab[i] = start;
// 	while (start > end)
// 	{
// 		tab[i] = start;
// 		start--;
// 		i++;
// 	}
// 	tab[i] = start;
// 	return (tab);
// }






// int		*ft_range(int start, int end)
// {
// 	int		*range;
// 	int		i;

// 	if (start > end)
// 		range = (int *)malloc(sizeof(int) * (start - end) + 1);
// 	else
// 		range = (int *)malloc(sizeof(int) * (end - start) + 1);
// 	i = 0;
// 	while (start != end)
// 	{
// 		range[i++] = start;
// 		start += (start > end) ? -1 : 1;
// 	}
// 	range[i] = start;
// 	return (range);
// }



int		*ft_range(int min, int max)
{
	int		*tab;
	int		i;

	if (min >= max)
		return (NULL);
	tab = (int*)malloc(sizeof(*tab) * (max - min));
	if (tab == NULL)
		return (NULL);
	else
	{
		i = -1;
		while (++i < max - min)
			tab[i] = min + i;
		return (tab);
	}
}


int			main()
{
	int		start;
	int		end;
	int		*arr;

	start = 0;
	end = 0;
	arr = ft_range(start, end);
	int	i = 0;
	while (start <= end)
	{
		printf("%i", arr[i]);
		start++;
		i++;
	}
	return (0);
}