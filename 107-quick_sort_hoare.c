#include "sort.h"
/**
 *swap - swaps two elements
 *@p: first element
 *@q: second element
 *Return: void
 */
void swap(int *p, int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}

/**
 *hoare_partition - divides the array into portions
 *@array: array
 *@low: lowest value element
 *@high: highest value element
 *@size: size of array
 *Return: final index of pivot
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot, a, z;

	pivot = array[high];
	for (a = low - 1, z = high + 1; a < z;)
	{
		do {
			a++;
		} while (array[a] < pivot);

		do {
			z--;
		} while (array[z] > pivot);

		if (a < z)
		{
			swap(array + a, array + z);
			print_array(array, size);
		}
	}
	return (z);
}

/**
 *hoareSort - sorts for the recursion
 *@array: array
 *@low: lowest element
 *@high: highest element
 *@size: size of array
 *Return: void
 */
void hoareSort(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = hoare_partition(array, low, high, size);
		hoareSort(array, low, pi, size);
		hoareSort(array, pi + 1, high, size);
	}
}

/**
 *quick_sort_hoare - sorts an array of integers in ascending order
 *using the Quick sort algorithm
 *@array: array sort
 *@size: size of array
 *Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoareSort(array, 0, size - 1, size);
}
