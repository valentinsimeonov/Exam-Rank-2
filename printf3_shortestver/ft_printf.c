#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int		translate(long long int n, int base, char *base_str)
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
		translate(n / base, base, base_str);
	hexlen++;
	index = n % base;
	write(1, &base_str[index], 1);
	return (hexlen + i);
}

int		print_str(va_list list)
{
	int		i;
	char	*str;

	i = 0;
	str = va_arg(list, char *);
	if (!str)
		str = "(null)";
	while (str[i])
		write(1, (str + i++), 1);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list		list;
	int			i;
	int			len;

	i = 0;
	len = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'd')
				len += translate(va_arg(list, int), 10, "0123456789");
			if (str[i] == 'x')
				len += translate(va_arg(list, long long int), 16, "0123456789abcdef");
			if (str[i] == 's')
				len += print_str(list);
			if (str[i] == '%')
				len += write(1, "%", 1);
			i++;
		}
		if (str[i] && str[i] != '%')
			len += write(1, (str + i++), 1);
	}
	va_end(list);
	return (len);
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