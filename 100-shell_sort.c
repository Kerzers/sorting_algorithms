#include "sort.h"

<<<<<<< HEAD
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		size_t i, j;
		int temp;

		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}

			array[j] = temp;
		}

		print_array(array, size);

		gap = (gap - 1) / 3;
	}
}

=======
/**
 *shell_sort - sorts an array of integers in ascending order
 *using the Shell sort algorithm, using the Knuth sequence
 *@array: the array to sort
 *@size: size of the array
 *
 */

void shell_sort(int *array, size_t size)
{
	size_t gab, i, j;
	int tmp;

	if (!array || size < 2)
		return;
	gab = 1;
	while (gab < size / 3)
		gab = (gab * 3) + 1;

	while (gab > 0)
	{
		for (i = gab; i < size; i++)
		{
			for (j = i; j >= gab; j -= gab)
			{
				if (array[j] > array[j - gab])
					break;
				tmp = array[j - gab];
				array[j - gab] = array[j];
				array[j] = tmp;
			}
		}
	print_array(array, size);
	gab = (gab - 1) / 3;
	}
}
>>>>>>> master
