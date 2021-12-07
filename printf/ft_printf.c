#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	list;
	int		len;

	i = 0;
	len = 0;
	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			len++;
			i++;
		}
		if (format[i] == '%')
		{
			len += check_placeholder(list, format[i + 1]);
			i += 2;
		}
	}
	va_end(list);
	return (len);
}

int	check_placeholder(va_list list, char c)
{
	int		len;

	if (c == 'd' || c == 'i')
		len = for_integer(list);
	if (c == 's')
		len = for_string(list);
	if (c == 'x')
		len = for_hexadecimal_lower(list);
	return (len);
}

int	for_integer(va_list list)
{
	long			number;
	unsigned int	len_int;

	number = va_arg(list, int);
	len_int = get_len_int(number);
	ft_putnbr_fd(number, 1);
	return (len_int);
}

int	for_string(va_list list)
{
	int			len_string;
	char		*string;

	string = va_arg(list, char *);
	if (string == NULL)
	{
		write(1, "(null)", 6);
		len_string = 6;
		return (len_string);
	}
	len_string = ft_strlen(string);
	write(1, string, len_string);
	return (len_string);
}

int	get_len_int(long int number)
{
	int		len;

	len = 1;
	if (number < 0)
	{
		number = number * -1;
		len++;
	}
	while (number / 10)
	{
		number = number / 10;
		len++;
	}
	return (len);
}

int	for_hexadecimal_lower(va_list list)
{
	unsigned int		number;
	int					len_hexa;

	number = va_arg(list, int);
	len_hexa = get_len_hexa(number);
	ft_put_hexa((unsigned long)number, 16, "0123456789abcdef");
	return (len_hexa);
}

void	ft_put_hexa(unsigned long number, int base_type, char *base)
{
	int		position;

	if (number / base_type != 0)
		ft_put_hexa(number / base_type, base_type, base);
	position = number % base_type;
	write(1, &base[position], 1);
}

int	get_len_hexa(unsigned long number)
{
	int		len_hexa;

	len_hexa = 1;
	while (number / 16)
	{
		number = number / 16;
		len_hexa++;
	}
	return (len_hexa);
}

