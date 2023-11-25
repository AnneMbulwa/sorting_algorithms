#include "sort.h"

/**
 *merge_subarray - sorts the split subarraies
 *@subarray: subarray of array list
 *@buf: buffer size
 *@begin: start of array list
 *@mid: middle
 *@end: end of array list
 *Return: void
 */
void merge_subarray(int *subarray, int *buf, size_t begin, size_t mid,
		size_t end)
{
	size_t x, y, z = 0;

	printf("Merging...\n[left]: ");
	print_array(subarray + begin, mid - begin);

	printf("[right]: ");
	print_array(subarray + mid, end - mid);

	for (x = begin, y = mid; x < mid && y < end; z++)
		buf[z] = (subarray[x] < subarray[y]) ? subarray[x++] :
			subarray[y++];
	for (; x < mid; x++)
		buf[z++] = subarray[x];
	for (; y < end; y++)
		buf[z++] = subarray[y];
	for (x = begin, z = 0; x < end; x++)
		subarray[x] = buf[z++];
	printf("[Done]: ");
	print_array(subarray + begin, end - begin);
}

/**
 *mergeSort - implements the recurvise merge sort
 *@subarray: subarray
 *@buf: buffer size
 *@begin: begining
 *@end: end
 *Return: void
 */
void mergeSort(int *subarray, int *buf, size_t begin, size_t end)
{
	size_t mid;

	if (end - begin > 1)
	{
		mid = begin + (end - begin) / 2;
		mergeSort(subarray, buf, begin, mid);
		mergeSort(subarray, buf, mid, end);
		merge_subarray(subarray, buf, begin, mid, end);
	}
}

/**
 *merge_sort - sorts an array of integers in ascending order
 *using the Merge sort algorithm
 *@array: array sort
 *@size: size of array
 *Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *buf;

	if (!array || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (!buf)
		return;
	mergeSort(array, buf, 0, size);

	free(buf);
}
