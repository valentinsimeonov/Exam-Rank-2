/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/

#include <stdio.h>

int ft_atoi_base(const char *str, int str_base)   //// NEED to run DEBUGGER
{
    int i = 0;
    int neg = 1;
    int result = 0;
    while (str[i] <= ' ')
        i++;
    if (str[i] == '-')
    {
        neg = -1;
        i++;
    }
    if (str[i] == '+')
        i++;
    while (str[i])
    {
        result = result * str_base;
        if (str[i] >= '0' && str[i] <= '9')
            result = result + str[i] - '0';
        else if (str[i] >= 'a' && str[i] <= 'f')
            result = result + str[i] - 'a' + 10;
        else if (str[i] >= 'A' && str[i] <= 'f')
            result = result + str[i] - 'A' + 10;
        i++;
    }
    return (neg * result);
}

int		main()
{
	char	str[] = "10";
	int		base = 16;

	printf("%d\n", ft_atoi_base(str, base));
	return (0);
}



