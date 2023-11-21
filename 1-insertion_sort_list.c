#include "sort.h"

/**
 *insertion_sort_list - sorts a doubly linked list of integers in ascending
 *order using the Insertion sort algorithm
 *@list: list of the double linked list
 *Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	curr = (*list)->next;
	while (curr != NULL)
	{
		tmp = curr->next;
		while (curr->prev != NULL && curr->n < curr->prev->n)
		{
			if (curr->next != NULL)
				curr->next->prev = curr->prev;
			curr->prev->next = curr->next;
			curr->next = curr->prev;
			curr->prev = curr->prev->prev;
			curr->next->prev = curr;

			if (curr->prev == NULL)
				*list = curr;

			print_list(*list);
		}
		curr = tmp;
	}
}
