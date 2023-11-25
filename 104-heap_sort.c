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
 *heapify - convert array into heap data structure / binary tree
 *@array: array sort
 *@size: size of array
 *@baze_idx: base index / root
 *@a: root
 *Return: void
 */
void heapify(int *array, size_t size, size_t baze_idx, size_t a)
{
	size_t largest = a;
	size_t left = 2 * a + 1;
	size_t right = 2 * a + 2;

	if (left < baze_idx && array[left] > array[largest])
		largest = left;
	if (right < baze_idx && array[right] > array[largest])
		largest = right;

	if (largest != a)
	{
		swap(array + a, array + largest);
		print_array(array, size);
		heapify(array, size, baze_idx, largest);
	}
}

/**
 *heap_sort - sorts an array of integers in ascending order using
 *the Heap sort algorithm
 *@array: array sort
 *@size: size of array
 *Return: void
 */
void heap_sort(int *array, size_t size)
{
	int a;

	if (array == NULL || size < 2)
		return;

	for (a = (size / 2) - 1; a >= 0; a--)
		heapify(array, size, size, a);
	for (a = size - 1; a > 0; a--)
	{
		swap(array, array + a);
		print_array(array, size);
		heapify(array, size, a, 0);
	}
}
