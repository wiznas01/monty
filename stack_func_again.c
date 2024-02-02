#include "monty.h"

/**
 * nop - does nothing
 * @stack: pointer to pointer that points to top node of stack
 * @line_number: line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * swap_nodes - swaps top 2 elements
 * @stack: pointer to pointer poniting to stack top node
 * @line_number: line number
 */
void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_nodes - adds the top two nodes
 * @stack: pointer of pointer pointing to stack top node
 * @line_number: line number
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "add");
	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**sub_nodes - substract top two elements
 * @stack: pointer of pointer pointing to stack top node
 * @line_number: line number
 */
void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int i;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
                more_err(8, line_number, "sub");
        (*stack) = (*stack)->next;
        i = (*stack)->n - (*stack)->prev->n;
        (*stack)->n = i;
        free((*stack)->prev);
        (*stack)->prev = NULL;
}

/**
 * div_nodes - adds to nodes
 * @stack: pointer to pointer pointing to stack top node
 * @line_number: line number
 */
void div_nodes(stack_t **stack, unsigned int line_number)
{
        int sum;

        if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
                more_err(8, line_number, "div");
        (*stack) = (*stack)->next;
        sum = (*stack)->n / (*stack)->prev->n;
        (*stack)->n = sum;
        free((*stack)->prev);
        (*stack)->prev = NULL;
}

