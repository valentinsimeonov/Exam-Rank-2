/*
Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **head, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

$>
*/

#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **head, void *data_ref, int (*cmp)())
{
	if (head == NULL || *head == NULL)
		return;
	t_list *temp = *head;
	if (cmp(temp->data, data_ref) == 0)
	{
		*head = temp->next;
		free(temp);
		ft_list_remove_if(head, data_ref, cmp);
	}
	temp = *head;
	ft_list_remove_if(&temp->next, data_ref, cmp);
}

/* --------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>

void	print_list(t_list **head)
{
	t_list *temp = *head;
	while (temp != 0)
	{
		printf("%s\n", temp->data);
		temp = temp->next;
	}
}

int		main(void)
{
	char straa[] = "String aa";
	t_list *aa = malloc(sizeof(t_list));
	aa->next = 0;
	aa->data = straa;

	char strbb[] = "String bb";
	t_list *bb = malloc(sizeof(t_list));
	bb->next = 0;
	bb->data = strbb;

	char strcc[] = "String cc";
	t_list *cc = malloc(sizeof(t_list));
	cc->next = 0;
	cc->data = strcc;

	char strdd[] = "String dd";
	t_list *dd = malloc(sizeof(t_list));
	dd->next = 0;
	dd->data = strdd;

	aa->next = bb;
	bb->next = cc;
	cc->next = dd;

	t_list **head = &aa;

	print_list(head);
	printf("----------\n");
	ft_list_remove_if(head, straa, strcmp);
	print_list(head);
}