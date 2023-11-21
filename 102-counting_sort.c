#include "sort.h"

/**
 *find_max - finds and gets the maximum value im the array
 *@array: array sort
 *@size: size of array
 *Return: maximum value(int)
 */
int find_max(int *array, int size)
{
	int max, a;

	for (max = array[0], a = 1; a < size; a++)
	{
		if (array[a] > max)
			max = array[a];
	}
	return (max);
}

/**
 *counting_sort - sorts an array of integers in ascending order
 *using the Counting sort algorithm
 *@array: array sort
 *@size: size of array
 *Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *countArray, *arr, max, a;

	if (array == NULL || size < 2)
		return;
	max = find_max(array, size);
	countArray = malloc(sizeof(int) * size);
	if (countArray == NULL)
		return;
	arr = malloc((max + 1) * sizeof(int));
	if (arr == NULL)
	{
		free(countArray);
		return;
	}

	for (a = 0; a < (max + 1); a++)
		countArray[a] = 0;
	for (a = 0; a < (int)size; a++)
		countArray[array[a]] += 1;
	for (a = 0; a < (max + 1); a++)
		countArray[a] += countArray[a - 1];
	print_array(countArray, max + 1);

	for (a = 0; a < (int)size; a++)
	{
		arr[countArray[array[a]] - 1] = array[a];
		countArray[array[a]] -= 1;
	}

	for (a = 0; a < (int)size; a++)
		array[a] = arr[a];

	free(arr);
	free(countArray);
}
