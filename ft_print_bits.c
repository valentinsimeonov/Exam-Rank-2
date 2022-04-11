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


int		ft_strlen(char *str)
{
	int		i;
	
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	print_bits(unsigned char octet)
{
	int		i;
	int		j;
	int		len;
	char	str[9] = "aaaaaaaa";

	i = 0;
	j = 0;
	while (i <= 7 && j <= 7)
	{
		if (octet >> i & 1)
			str[j] = '1';
		else
			str[j] = '0';
		i++;
		j++;
	}
	len = ft_strlen(str);
	while (len >= 0)
	{
		write(1, &str[len - 1], 1);
		len--;
	}
}

int	main()
{
	int	octet;

	octet = 7;
	print_bits(octet);
	return (0);
}