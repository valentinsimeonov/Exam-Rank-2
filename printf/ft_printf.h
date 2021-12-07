#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		check_placeholder(va_list list, char c);
int		for_integer(va_list list);
int		get_len_int(long int number);

int		for_string(va_list list);

int		for_hexadecimal_lower(va_list list);
void	ft_put_hexa(unsigned long number, int base_type, char *base);
int		get_len_hexa(unsigned long number);

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);

#endif
