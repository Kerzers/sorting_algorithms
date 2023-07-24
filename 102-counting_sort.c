#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in
 * ascending order using Counting Sort.
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	size_t i, max;
	int *count, *output;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; ++i)
	{
		if (array[i] > (int)max)
			max = array[i];
	}

	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;

	for (i = 0; i <= max; ++i)
		count[i] = 0;

	for (i = 0; i < size; ++i)
		count[array[i]]++;

	for (i = 1; i < max + 1; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;

	for (i = size - 1; (int)i >= 0; i--)
	{
		count[array[i]]--;
		output[count[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
