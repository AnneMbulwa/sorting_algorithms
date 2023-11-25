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
	int index = 0, m_index, temp;

	if (array == NULL || size < 2)
		return;
	for (a = 0; a < size - 1; a++)
	{
		m_index = array[a];
		for (b = a + 1; b < size; b++)
			if (array[b] < m_index)
			{
				m_index = array[b];
				index = b;
			}


		if (m_index != array[a])
		{
			temp = array[a];
			array[a] = array[index];
			array[index] = temp;
			print_array(array, size);
		}
	}
}
