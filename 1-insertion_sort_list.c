#include "sort.h"

/**
 *insertion_sort_list - sorts a doubly linked list of integers in ascending
 *order using the Insertion sort algorithm
 *@list: list of the double linked list
 *Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *temp;
	listint_t *a, *b, *c;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	curr = *list;
	while (curr != NULL)
	{
		 if (curr->prev != NULL && curr->n < curr->prev->n)
		{
			temp = curr->prev->prev;
			a = curr->prev;
			b = curr;
			c = curr->next;

			a->next = c;
			if (c)
				c->prev = a;
			b->next = a;
			b->prev = temp;
			if (temp)
				temp->next = b;
			else
				*list = b;
			a->prev = b;
			curr = *list;
			print_list(*list);
			continue;
		}
		 curr = curr->next;
	}
}
