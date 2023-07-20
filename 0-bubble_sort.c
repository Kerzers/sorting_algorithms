#include "sort.h"

/**
 *bubble_sort - sorts an array of integers in ascending order
 *using the Bubble sort algorithm
 *
 *@array: pointer to the array of integer
 *@size: size of the array
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, tmp, swap = 1, n = size;

	while (swap)
	{
		swap = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, n);
				swap = 1;
			}
		}
		size = size - 1;
	}
}
