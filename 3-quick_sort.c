#include "sort.h"

/**
 *swap - function that swaps two elements
 *@array: array sort
 *@p: first element
 *@q: second element
 *@size: size of array
 */
void swap(int *array, int *p, int *q, size_t size)
{
	int temp;

	temp = *p;
	*p = *q;
	*q = temp;
	print_array(array, size);
}

/**
 *partition - partitions the elements in the array
 *@array: array sort
 *@low: low element value
 *@high: high value element
 *@size: size of array
 *Return: pivot position
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int a = low;
	int b;

	for (b = low; b < high; b++)
	{
		if (array[b] < pivot)
		{
			if (a != b)
				swap(array, &array[a], &array[b], size);
			a++;
		}
	}
	if (a != high)
		swap(array, &array[a], &array[high], size);

	return (a);
}

/**
 *quickSort - sorts the elements
 *@array: array sort
 *@low: low element value
 *@high: high element value
 *@size: size of array
 *Return: void
 */
void quickSort(int *array, int low, int high, size_t size)
{
	int pi = 0;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		quickSort(array, low, pi - 1, size);
		quickSort(array, pi + 1, high, size);
	}
}

/**
 *quick_sort - sorts an array of integers in ascending order
 *using the Quick sort algorithm
 *@array: array sort
 *@size: size of array
 *Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}
