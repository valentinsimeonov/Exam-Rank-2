/*
Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100
 */

#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int		i;

	i = 0;
	while(i <= 7)
	{
		if (octet >> i & 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i++;
	}
	return (0);
}

int	main()
{
	int		octet;

	octet = 7;
	reverse_bits(octet);
	return (0);
}