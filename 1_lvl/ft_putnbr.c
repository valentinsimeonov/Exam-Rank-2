void	ft_putnbr(int num)
{
	if (num < 0)
	{
		write(1, "-", 1);
		num = num * (-1);
	}
	if (n >= 10)
	{
		ft_putnbr(num / 10);
		num = num % 10;
	}
	if (num < 10)
	{
		ft_putchar(num + '0');
	}
}

void	ft_putnbr(int num)
{
	if (num < 0)
	{
		write(1, "-", 1);
		num = num * (-1);
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		num = num % 10;
	}
	if (num < 10)
	{
		ft_putchar(num + '0');
	}
}

void ft_putnbr(num)
{
	if (num < 0)
	{
		write(1, "-", 1);
		num = num * (-1);
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		num = num % 10;
	}
	if (num < 10)
	{
		ft_putchar(num + '0');
	}
}