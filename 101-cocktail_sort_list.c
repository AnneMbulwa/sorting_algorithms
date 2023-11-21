#include "sort.h"

/**
 *swap_list - swaps the elements in dobouly linked list
 *@x1: pointer one
 *@x2: pointer two
 *@n: integer
 */
void swap_list(listint_t **x1, listint_t **x2, int n)
{
	listint_t *aux, *temp;

	aux = *x1;
	temp = *x2;

	aux->next = temp->next;
	temp->prev = aux->prev;

	if (temp->next)
		temp->next->prev = aux;

	if (aux->prev)
		aux->prev->next = temp;

	aux->prev = temp;
	temp->next = aux;

	if (n == 0)
		*x1 = temp;
	else
		*x2 = aux;
}

/**
 * increase_sort_right - move bigger element towards right or the end
 *@x: pointer to the max element
 *@max: limit of the list
 *@list: list of integers/ values
 */
void increase_sort_right(listint_t **x, listint_t **max, listint_t **list)
{
	listint_t *aux;

	aux = *x;

	while (aux != *max && aux->next != *max)
	{
		if (aux->n > aux->next->n)
		{
			swap_list(&aux, &(aux->next), 0);
			if (aux->prev == NULL)
				*list = aux;
			print_list(*list);
		}
		aux = aux->next;
	}

	*max = aux;
	*x = aux;
}

/**
 * decrease_sort_left - moves the small element values toward left or start
 *@x: pointer to the small value element
 *@max: limit size of the list
 *@list: list of values/ integers
 *Return: void
 */
void decrease_sort_left(listint_t **x, listint_t **max, listint_t **list)
{
	listint_t *aux;

	aux = *x;

	while (aux != *max && aux->prev != *max)
	{
		if (aux->n < aux->prev->n)
		{
			swap_list(&(aux->prev), &aux, 1);
			if (aux->prev->prev == NULL)
				*list = aux->prev;
			print_list(*list);
		}
		aux = aux->prev;
	}

	*max = aux;
	*x = aux;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 *@list: list of doubly linked list
 *Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *max1, *max2, *x;

	if (list == NULL)
		return;

	if (*list == NULL)
		return;

	max1 = max2 = NULL;
	x = *list;

	do {
		increase_sort_right(&x, &max1, list);
		decrease_sort_left(&x, &max2, list);
	} while (max1 != max2);
}
