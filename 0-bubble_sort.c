#include "sort.h"

/**
 *bubble_sort - sorts an array of integers in ascending order using
 *the Bubble sort algorithm
 *@array: list of array
 *@size: size of the array
 *Return: void
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int a, b;
	int temp;

	if (size < 2)
		return;

	for (a = 0; a < size; a++)
	{
		for (b = 0; b < size - a - 1; b++)
			if (array[b] > array[b + 1])
			{
				temp = array[b];
				array[b] = array[b + 1];
				array[b + 1] = temp;
				print_array(array, size);
			}
	}
}
