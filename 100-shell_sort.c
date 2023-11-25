#include "sort.h"

/**
 *swap - swaps two elements
 *@p: first element
 *@q: second element
 */
void swap(int *p, int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}

/**
 *shell_sort - sorts an array of integers in ascending order
 *using the Shell sort algorithm, using the Knuth sequence
 *@array: array
 *@size: size of array
 *Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, a, b;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = (gap * 3) + 1;
	for (; gap >= 1; gap /= 3)
	{
		for (a = gap; a < size; a++)
		{
			b = a;
			while (b > gap - 1 && array[b - gap] > array[b])
			{
				swap(array + b, array + (b - gap));
				b = b - gap;
			}
		}
		print_array(array, size);
	}
}
