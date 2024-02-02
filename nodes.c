#include "monty.h"

/**
 * free_nodes - Frees the memory allocated for a linked list.
 * @head: Pointer to the head of the linked list.
 *
 * This function frees the memory associated with each node
 * in the linked list starting from the specified head.
 *
 * @head: Pointer to the head of the linked list.
 */
void free_nodes(void)
{
	stack_t *current = head;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

/**
 * add_to_queue - Adds a new node to the end of a linked list.
 * @head: Pointer to the head of the linked list.
 * @data: Data to be stored in the new node.
 *
 * This function adds a new node with the specified data to
 * the end of the linked list.
 *
 * @head: Pointer to the head of the linked lists
 */
void add_to_queue(stack_t **head, unsigned int)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *last = *head;

	if (new_node == NULL)
	{
		return;
	}

	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return;
	}

	while (last->next != NULL)
		last = last->next;

	last->next = new_node;
}

