# include <unistd.h>
# include <stdarg.h>

size_t	ft_strlen(const char *s)
{
	size_t	c = 0;

	if (!s)
		return (0);
	while (s[c] != '\0')
		c++;
	return (c);
}

int	ft_putnbr_base(long n, char *base)
{
	long	base_len = ft_strlen(base);
	int		counter = 0;

	if (n < 0)
	{
		counter += write(1, "-", 1);
		n = -(n);
	}
	if (n == 0)
	{
		counter += write(1, "0", 1);
		return (counter);
	}
	if (n >= base_len)
	{
		ft_putnbr_base(n / base_len, base);
		counter += write(1, &base[n % base_len], 1);
	}
	else if (n < base_len)
		counter += write(1, &base[n], 1);
	return (counter);
}

int	ft_print_string(char *c)
{
	int		i = 0, counter = 0;

	if (!c)
		c = "(null)";
	while (c[i])
	{
		counter += write(1, &c[i], 1);
		i++;
	}
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	int		rtn = 0, i = 0;
	va_list args;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				rtn += ft_print_string(va_arg(args, char *));
			else if (format[i] == 'd')
				rtn += ft_putnbr_base(va_arg(args, int), "0123456789");
			else if (format[i] == 'x')
				rtn += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
			else if (format[i] == '%')
				rtn += write(1, "%", 1);
		}
		else
			rtn += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (rtn);
}

#include <stdio.h>

int main()
{
	char *ch = "(a string)";
	


	ft_printf("%d %d %d %d %d", -2147483647, 17, 3, 1300, -400);
	ft_printf("\n");

	ft_printf("%x %x %x %x %x", 0, 40, -23, -2147483647, 7);
	ft_printf("\n");

	ft_printf("Hello this is %s in a string", ch);
	ft_printf("\n");

	ft_printf("Percentages: %%");
	ft_printf("\n");

	printf("\n");
	printf("\n");

	printf("%d %d %d %d %d", -2147483647, 17, 3, 1300, -400);
	printf("\n");

	printf("%x %x %x %x %x", 0, 40, -23, -2147483647, 7);
	printf("\n");

	printf("Hello this is %s in a string", ch);
	printf("\n");

	printf("Percentages: %%");
	printf("\n");

	return (0);
}