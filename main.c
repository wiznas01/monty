#include "monty.h"

stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: void
 */

int main(int argc, char *arg[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(arg[1]);
	free_nodes();
	return (0);
}

/**
 * create_node - creates a node
 * @n: number to go inside the node
 * Return: pointerbto node if successful, otherwise NULL
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}
