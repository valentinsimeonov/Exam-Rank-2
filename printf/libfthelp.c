#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	temp;

	temp = n;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (temp < 0)
	{
		ft_putchar_fd('-', fd);
		temp *= -1;
	}
	if (temp < 10)
	{
		ft_putchar_fd(temp + '0', fd);
	}
	else
	{
		ft_putnbr_fd(temp / 10, fd);
		ft_putnbr_fd(temp % 10, fd);
	}
}

int putnbr(long n, char *base)
{
	long baselen = ft_strlen(base);
	int counter = 0;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -(n);
	}
	if (n == 0)
	{
		write(1, "0", 1)
	}
	if (n <= baselen)
	{
		
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			write(fd, s++, 1);
		}
	}
}

size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
