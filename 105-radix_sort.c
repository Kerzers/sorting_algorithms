#include "sort.h"

void radix_countSort(int *array, size_t size, int digit_pos);

/**
 *radix_sort - sorts an array of integers in ascending order
 *using the LSD Radix sort algorithm
 *
 *@array: array to sort
 *@size: size of the array
 *
 */
void radix_sort(int *array, size_t size)
{
	int max;
	size_t i;

	if (!array || size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; ++i)
	{
		if (array[i] > (int)max)
			max = array[i];
	}
	for (i = 1; max / i > 0; i *= 10)
	{
		radix_countSort(array, size, i);
		print_array(array, size);
	}
}

/**
 *radix_countSort - Counting Sort for a specific digit position
 *@array: array to sort
 *@size: size of the array
 *@digit_pos: the position of a digit (1= first digit, 10= second digit)
 */
void radix_countSort(int *array, size_t size, int digit_pos)
{
	int *count, *output;
	size_t i;

	count = malloc((10) * sizeof(int));
	if (count == NULL)
		return;

	for (i = 0; i < 10; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[(array[i] / digit_pos) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;

	for (i = size - 1; (int)i >= 0; i--)
	{
		count[(array[i] / digit_pos) % 10]--;
		output[count[(array[i] / digit_pos) % 10]] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
