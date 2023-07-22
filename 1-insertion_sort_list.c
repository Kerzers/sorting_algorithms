#include "sort.h"
void swapAdjacNodes(listint_t **head, listint_t *node1);

/**
 *insertion_sort_list - sorts a doubly linked list of integers in
 *ascending order using the Insertion sort algorithm
 *
 *@list: reference to the header of a list
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *iter;

	if (!list || !*list || !((*list)->next))
		return;
	iter = (*list)->next;
	while (iter)
	{
		current = iter;
		while (current != *list && current->prev->n > current->n)
		{
			swapAdjacNodes(list, current->prev);
			print_list(*list);
		}
		iter = iter->next;
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
