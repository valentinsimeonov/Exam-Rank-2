/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/

// Passed Moulinette 07.07.2022

#include <unistd.h>

int		skip_whitespace(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t')
		++i;
	return (i);
}

int		ft_wordlen(char *str)
{
	int i = 0;

	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		++i;
	return (i);
}

void	epur_str(char *str)
{
	int i;
	int is_first;
	int	wordlen;

	i = 0;
	is_first = 1;
	wordlen = 0;
	i = skip_whitespace(str, i);
	while (str[i])
	{
		i = skip_whitespace(str, i);
		if (is_first == 0)
			write(1, " ", 1);
		wordlen = ft_wordlen(str + i);
		write(1, str + i, wordlen);
		is_first = 0;
		i = i + wordlen;
		i = skip_whitespace(str, i);
	}
	if (wordlen != 0)
		write(1, " ", 1);
}

int		main(int argc, char **argv)
{
	if (argc >= 2)
	{
		char *str = argv[1];
		int i = 0;
		int	wordlen;
		int	begin;

		i = 0;
		wordlen = 0;
		i = skip_whitespace(str, i);
		begin = i;
		wordlen = ft_wordlen(str + i);
		epur_str(str + i + wordlen);
		write(1, str + begin, wordlen);
	}
	write(1, "\n", 1);
	return (0);
}