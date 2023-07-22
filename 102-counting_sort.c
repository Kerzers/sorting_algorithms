#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using Counting Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/* Find the maximum element in the array */
	int max_element = array[0];
	for (size_t i = 1; i < size; ++i) {
		if (array[i] > max_element)
			max_element = array[i];
	}

	int *counting_array = malloc((max_element + 1) * sizeof(int));
	if (counting_array == NULL)
		return;

	for (int i = 0; i <= max_element; ++i)
		counting_array[i] = 0;

	for (size_t i = 0; i < size; ++i)
		counting_array[array[i]]++;

	size_t j = 0;
	for (int i = 0; i <= max_element; ++i) {
		while (counting_array[i] > 0) {
			array[j] = i;
			counting_array[i]--;
			j++;
		}
	}

	free(counting_array);

	printf("Counting array: ");
	print_array(counting_array, max_element + 1);
}

