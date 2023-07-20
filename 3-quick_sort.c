#include "sort.h"

/**
 * partition - Lomuto partition scheme
 * @array: The array to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: Number of elements in the array
 * Return: Index of the pivot element after partitioning
 */
size_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
    int pivot, tmp;
    ssize_t i, j;

    pivot = array[high];
    i = low - 1;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
                print_array(array, size);
            }
        }
    }

    if (array[i + 1] != array[high])
    {
        tmp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = tmp;
        print_array(array, size);
    }

    return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function to implement quicksort
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: Number of elements in the array
 */
void quick_sort_recursive(int *array, ssize_t low, ssize_t high, size_t size)
{
    ssize_t pi;

    if (low < high)
    {
        pi = partition(array, low, high, size);
        quick_sort_recursive(array, low, pi - 1, size);
        quick_sort_recursive(array, pi + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
    if (array && size > 1)
    {
        quick_sort_recursive(array, 0, size - 1, size);
    }
}
