#include "sort.h"
#include <stdlib.h>

void copy_array(int *origin, size_t iBegin, size_t iEnd, int *w_array);
void split_merge(int *origin, size_t iBegin, size_t iEnd, int *w_array);
void merge(int *origin, size_t iBegin, size_t iMid, size_t iEnd, int *w_array);

/**
 * merge_sort - sorts an array of integers in ascending
 * order using the Merge sort algorithm (Top-down)
 * @array: array to be sorted
 * @size: size of the array
 *
 */
void merge_sort(int *array, size_t size)
{
	int *working_array;

	if (!array || size < 2)
		return;

	working_array = malloc(size * sizeof(int));
	if (!working_array)
		return;
	copy_array(array, 0, size, working_array);
	split_merge(array, 0, size, working_array);
	free(working_array);
}

/**
 *copy_array - copies the original array to the working one
 *@origin: original array
 *@iBegin: index of begining
 *@iEnd: index of the end (don't reach by the array)
 *@w_array: working array
 */
void copy_array(int *origin, size_t iBegin, size_t iEnd, int *w_array)
{
	size_t i;

	for (i = iBegin; i < iEnd; i++)
		w_array[i] = origin[i];
}

/**
 *split_merge - split working array into 2 halves recuresively
 *@origin: original array
 *@iBegin: index of begining
 *@iEnd: index of the end (don't reach by the array)
 *@w_array: working array
 *
 */
void split_merge(int *origin, size_t iBegin, size_t iEnd, int *w_array)
{
	size_t iMid;

	if (iEnd - iBegin <= 1)
		return;
	iMid = (iBegin + iEnd) / 2;
	split_merge(origin, iBegin, iMid, w_array);
	split_merge(origin, iMid, iEnd, w_array);
	merge(origin, iBegin, iMid, iEnd, w_array);
}

/**
 *merge - merge both halves from working array to origin
 *@origin: original array
 *@iBegin: index of begining of the array working array
 *@iMid: index of the begining of the right half
 *@iEnd: index of the end (it isn't reached by the array)
 *@w_array: working array
 *
 *
 */
void merge(int *origin, size_t iBegin, size_t iMid, size_t iEnd, int *w_array)
{
	size_t l = iBegin, r = iMid, i = iBegin;

	printf("Merging...\n");
	printf("[left]: ");
	print_array((origin + iBegin), (iMid - iBegin));
	printf("[right]: ");
	print_array((origin + iMid), (iEnd - iMid));

	while (l < iMid && r < iEnd)
	{
		if (w_array[l] < w_array[r])
		{
			origin[i] = w_array[l];
			i++;
			l++;
		}
		else
		{	origin[i] = w_array[r];
			i++;
			r++;
		}
	}
	while (l < iMid)
	{
		origin[i] = w_array[l];
		i++;
		l++;
	}
	while (r < iEnd)
	{
		origin[i] = w_array[r];
		i++;
		r++;
	}
	printf("[Done]: ");
	print_array((origin + iBegin), (iEnd - iBegin));
	copy_array(origin, iBegin, iEnd, w_array);
}
