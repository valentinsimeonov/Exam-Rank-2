/*

Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100
*/

/*
		128  64   32   16       8    4   2    1
		---------------------------------------
	65	0    1    0     0       0    0   0    1
	20	0    0    0     1       0    1   0    0
*/
// Passed Moulinette 23.04.2022
#include <stdio.h>

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

int	main()
{
	int		octet;

	octet = 20;
	printf("%d", swap_bits(octet));
	return (0);
}

