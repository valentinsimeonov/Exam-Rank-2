/*
Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...    		   is sparta, then again, maybe    	not" | cat -e
not$
"this        ...    		   is sparta, then again, maybe	 	 	 not	 	 	 " | cat -e
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>


My Tests:
"FORPONY" | cat -e
"FOR	PONY" | cat -e
"FOR 	PONY" | cat -e
"FOR 	 PONY" | cat -e
"FOR	 	PONY" | cat -e
"FOR	 	PONY	" | cat -e
"FOR	 	PONY " | cat -e
"FOR	 	PONY 	" | cat -e
"FOR	 	PONY 	 " | cat -e
"FOR	 	PONY 	 	" | cat -e

The Ultimate Tests:
"FOR 	 			   				     	 	 						      PONY					        	 	 				 	 		 					    	 		 	 	 	 " | cat -e

"    				 	 	 	 	 	++Space	 			   			23   			 	 	 	 	and Tabs		The 	 	=- 	Final 				 	 		 Frontier	     	 	 						      PONY					        	 	 				 	 		 					    	 		 	 	 	 " | cat -e
"+? 	 	 ? 	 	\ 	 			    				 	 	 	 	 	++Space	 			   			23   			 	 	 	 	and Tabs		The 	 	=- 	Final 				 	 		 Frontier	     	 	 						      PONY					        	 	 				 	 		 					    	 		 	 	 	 " | cat -e
*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	int		start;

	i = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == ' ' && argv[1][i + 1] != ' ' && argv[1][i + 1] != 9 && argv[1][i + 1] != '\0')
			start = i + 1;
		else if (argv[1][i] == 9 && argv[1][i + 1] != ' ' && argv[1][i + 1] != 9 && argv[1][i + 1] != '\0')
			start = i + 1;
		i++;
	}
	while (argv[1][start] != ' ' && argv[1][start] != '\0' && argv[1][start] != 9)
	{
		write(1, &argv[1][start], 1);
		start++;
	}
	write(1, "\n", 1);
	return (0);
}
