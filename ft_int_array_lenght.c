/*
* C program to get length of int array
*/

#include <unistd.h>
#include <stdio.h>

int main()
{
	int length;

	length = 0;
	int arr[] = {2,4,6,8,9,4};
	length  = sizeof(arr)/sizeof(int);
	printf("%d",length );
	return 0;
}
