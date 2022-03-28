#include <unistd.h>


void	ft_putchar(int c)
{
	write(1, &c, 1);
}

/* Recursive putnbr */
void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48);
}

int	main()
{
	int		num;

	num = 23;
	ft_putnbr(num);
	return (0);
}
