#include "sort.h"

void swap(int *a, int *b);
void heapify(int *a, size_t size);
void siftDown(int *a, size_t start, size_t end, size_t size);

/**
 *heap_sort - sorts an array of integers in ascending order using
 *the sift down  Heap sort algorithm
 *@array: the array to be sorted
 *@size: size of the array
 *
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (!array || size < 2)
		return;

	heapify(array, size);
	end = size - 1;
	while (end > 0)
	{
		swap(&array[end], &array[0]);
		print_array(array, size);
		end = end - 1;
		siftDown(array, 0, end, size);
	}
}

/**
 *swap - swaps two elements
 *@a: pointer to element 1
 *@b: pointer to element 2
 *
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 *heapify - builds the heap in array a so that largest value is at the root
 *@a: array of integers
 *@size: size of the array
 */
void heapify(int *a, size_t size)
{
	size_t start;

	/* start is assigned the index in 'a' of the last parent node)*/
	start = ((size - 1) - 1) / 2;
	while ((int)start >= 0)
	{
		siftDown(a, start, size - 1, size);
		start = start - 1;
	}
}

/**
 *siftDown - moves the element down the tree to its correct position
 *so the subtree rooted at that node satisfies the max-heap property.
 *
 *@a: array
 *@start: the index of the root
 *@end: last element of the array
 *@size: size of the array to be sorted
 */
void siftDown(int *a, size_t start, size_t end, size_t size)
{
	size_t root = start, idxSwap, child;

	while ((2 * root + 1) <= end)
	{
		child = 2 * root + 1;
		idxSwap = root;
		if (a[idxSwap] < a[child])
			idxSwap = child;
		if (child + 1 <= end && a[idxSwap] < a[child + 1])
			idxSwap = child + 1;
		if (idxSwap == root)
			return;
		swap(&a[root], &a[idxSwap]);
		print_array(a, size);
		root = idxSwap;
	}
}
