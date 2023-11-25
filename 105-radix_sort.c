#include "sort.h"

/**
 *get_max - gets the maximum or largest value
 *@array: array
 *@size: size of array
 *Return: max value
 */
int get_max(int *array, int size)
{
	int a;
	int mx = array[0];

	for (a = 1; a < size; a++)
		if (array[a] > mx)
			mx = array[a];
	return (mx);
}

/**
 *radix_countingSort - function that sorts the array
 *@array: array
 *@size: size
 *@exp: significant digit
 *@buf: buffer
 *
 */
void radix_countingSort(int *array, size_t size, size_t exp, int *buf)
{
	size_t a;
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (a = 0; a < size; a++)
		count[(array[a] / exp) % 10] += 1;
	for (a = 0; a < 10; a++)
		count[a] = count[a - 1];
	for (a = size - 1; (int)a >= 0; a--)
	{
		buf[count[(array[a] / exp) % 10] - 1] = array[a];
		count[(array[a] / exp) % 10] -= 1;
	}
	for (a = 0; a < size; a++)
		array[a] = buf[a];
}

/**
 *radix_sort - sorts an array of integers in ascending order using
 *the Radix sort algorithm
 *@array: array
 *@size: size
 *Return: void
 */
void radix_sort(int *array, size_t size)
{
	int mx, exp, *buf;

	if (!array || size < 2)
		return;
	buf = malloc(sizeof(int) * size);
	if (!buf)
		return;
	mx = get_max(array, size);

	for (exp = 1; mx / exp > 0; exp *= 10)
	{
		radix_countingSort(array, size, exp, buf);
		print_array(array, size);
	}
	free(buf);
}
