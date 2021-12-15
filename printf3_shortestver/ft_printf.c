#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int	dectohex(long long int n, int base, char *base_str)
{
	int			index;
	static int	hexlen;
	int			i;

	hexlen = 0;
	i = 0;
	if (n < 0 && base == 10)
	{
		write(1, "-", 1);
		n = n * (-1);
		i++;
	}
	if (n / base)
		dectohex(n / base, base, base_str);
	hexlen++;
	index = n % base;
	write(1, &base_str[index], 1);
	return (hexlen + i);
}

int	wstr(va_list ap)
{
	int		i;
	char	*string;

	i = 0;
	string = va_arg(ap, char *);
	if (!string)
		string = "(null)";
	while (*(string + i))
		write(1, (string + i++), 1);
	return (i);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			i;
	int			j;

	i = 0;
	j = 0;
	va_start(ap, fmt);
	while (*(fmt + i))
	{
		if (*(fmt + i) == '%')
		{
			i++;
			if (*(fmt + i) == 'd')
				j += dectohex(va_arg(ap, int), 10, "0123456789");
			if (*(fmt + i) == 'x')
				j += dectohex(va_arg(ap, long long int), 16, "0123456789abcdef");
			if (*(fmt + i) == 's')
				j += wstr(ap);
			if (*(fmt + i) == '%')
				j += write(1, "%", 1);
			i++;
		}
		if (*(fmt + i) && *(fmt + i) != '%')
			j += write(1, (fmt + i++), 1);
	}
	va_end(ap);
	return (j);
}

int main()
{
	char *ch = "(a string)";
	int	i;


	i = ft_printf("%d %d %d %d %d", -2147483647, 17, 3, 1300, -400);
	ft_printf("\n");
	ft_printf("%d", i);
	ft_printf("\n");

	i = ft_printf("%x %x %x %x %x", 0, 40, -23, -2147483647, 7);
	ft_printf("\n");
	ft_printf("%d", i);
	ft_printf("\n");

	i = ft_printf("Hello this is %s in a string", ch);
	ft_printf("\n");
	ft_printf("%d", i);
	ft_printf("\n");

	i = ft_printf("Percentages: %%");
	ft_printf("\n");
	ft_printf("%d", i);
	ft_printf("\n");

	printf("\n");
	printf("\n");

	i = printf("%d %d %d %d %d", -2147483647, 17, 3, 1300, -400);
	printf("\n");
	printf("%d", i);
	printf("\n");

	i = printf("%x %x %x %x %x", 0, 40, -23, -2147483647, 7);
	printf("\n");
	printf("%d", i);
	printf("\n");

	i = printf("Hello this is %s in a string", ch);
	printf("\n");
	printf("%d", i);
	printf("\n");

	i = printf("Percentages: %%");
	printf("\n");
	printf("%d", i);
	printf("\n");

	return (0);
}
