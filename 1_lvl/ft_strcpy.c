/*
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions: 
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
	int		i;

	i = 0;
	while(s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

int main()
{
	char	*src;         // A Pointer to a String that can NOT be Modified
	char	dst[] = "";   // A Char Array that CAN Be Modified this Way

	src = "HEllo";
	ft_strcpy(dst, src);
	printf("%s", dst);
	return (0);
}
