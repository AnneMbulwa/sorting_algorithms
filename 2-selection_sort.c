#include "sort.h"

/**
 *selection_sort - sorts an array of integers in ascending order
 *using the Selection sort algorithm
 *@array: array
 *@size: size of array
 *Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t a, b;
	int m_index, tmp;

	if (array == NULL || size < 2)
		return;
	for (a = 0; a < size; a++)
	{
		m_index = a;
		for (b = a + 1; b < size; b++)
			if (array[b] < array[m_index])
				m_index = b;

		if (m_index != array[a])
		{
			tmp = array[a];
			array[a] = array[m_index];
			array[m_index] = tmp;
			print_array(array, size);
		}
	}
}
