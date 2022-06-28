/*
Assignment name  : first_word

Expected files   : first_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its first word, followed by a
newline.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...       is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>

My Tests:

./a.out "" | cat -e
./a.out | cat -e
./a.out "A"  | cat -e
./a.out "\!\@#\!\@$\@#%\$\$#%$%^%$^^%&^%&&*&*" | cat -e
./a.out \\ | cat -e
./a.out "	lorem,ipsum  " | cat -e
./a.out "		 	 	lorem,ipsum  " | cat -e
./a.out "  	 	 	 		lorem,ipsum			 	 	 	 	" | cat -e
./a.out "    			lorem,ipsum     			 	 	 	 	" | cat -e
./a.out " 				     lorem,ipsum			 	 	 	 	 	 " | cat -e
./a.out "					" | cat -e
./a.out "                   " | cat -e
*/


// Passed Moulinette on 21.06.2022
// Passed Moulinette on 23.06.2022
#include <unistd.h>

int			main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		while (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '\t')
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
