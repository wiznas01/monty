#include "monty.h"

/**
 * print_char - prints the ASCII value
 * @stack: pointer of pointer of top node of stack
 * @line_number: line number
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		string_err(10, line_number);
	printf("%d\n", ascii);
}

/**
 * print_str - prints a string
 * @stack: poinyer of pointer of top of stack
 * @ln: line number\
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - rotates the first node of stack to the bottom
 * @stack: pointer of pointer of top of stack
 * @ln: line number
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr - rotates the first node of stack to the bottom
 * @stack: pointer of pointer of top of stack
 * @ln: line number
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
        stack_t *tmp;

        if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
                return;

        tmp = *stack;
        while (tmp->next != NULL)
                tmp = tmp->next;

        tmp->next = *stack;
        (*stack)->prev = tmp;
        *stack = (*stack)->next;
        (*stack)->prev->next = NULL;
        (*stack)->prev = NULL;
}

