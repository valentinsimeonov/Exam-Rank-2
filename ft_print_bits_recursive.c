/*
Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"
*/

#include <unistd.h>

void	rec(unsigned char octet, int depth);

void	print_bits(unsigned char octet)
{
	rec(octet, 8);
}

void	rec(unsigned char octet, int depth)
{
	if (depth)
	{
		rec(octet >> 1, depth - 1);
		if (octet & 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
}

int	main()
{
	int	octet;

	octet = 7;
	print_bits(octet);
	return (0);
}