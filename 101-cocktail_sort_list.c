#include "sort.h"
void swapAdjacNodes(listint_t **head, listint_t *node1);

/**
 *cocktail_sort_list - sorts doubly linked list of integers in ascending order
 * using the Cocktail shaker sort algorithm
 *
 *@list: list to sort
 *
 */
void cocktail_sort_list(listint_t **list)
{
	int swap = 1;
	listint_t *iter, *last;

	if (!list || !*list || !((*list)->next))
		return;
	while (swap)
	{
		swap = 0;
		for (iter = *list; iter->next != NULL; iter = iter->next)
		{
			if (iter->n > iter->next->n)
			{
				swapAdjacNodes(list, iter);
				iter = iter->prev;
				print_list(*list);
				swap = 1;
			}
			if (iter->next->next == NULL)
				last = iter;
		}
		if (!swap)
			break;
		swap = 0;
		for (iter = last; iter->prev != NULL; iter = iter->prev)
		{
			if (iter->n < iter->prev->n)
			{
				swapAdjacNodes(list, iter->prev);
				iter = iter->next;
				print_list(*list);
				swap = 1;
			}
		}
	}
}

/**
 *swapAdjacNodes - swaps two adjacent nodes
 *@head: the ref of head to a list
 *@node1: node to swap with the next one
 *
 */

void swapAdjacNodes(listint_t **head, listint_t *node1)
{
	listint_t *node2;

	if (!node1 || !node1->next)
		return;
	node2 = node1->next;

	if (node1->prev)
		node1->prev->next = node2;
	else
		*head = node2;
	node2->prev = node1->prev;
	node1->prev = node2;

	if (node2->next)
	{
		node1->next = node2->next;
		node2->next->prev = node1;
	} else
		node1->next = NULL;
	node2->next = node1;
}
