#include "monty.h"

/**
 * mod_nodes - adds to nodes
 * @stack: pointer to pointer pointing to stack top node
 * @line_number: line number
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
        int sum;

        if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
                more_err(8, line_number, "mod");
        (*stack) = (*stack)->next;
        sum = (*stack)->n % (*stack)->prev->n;
        (*stack)->n = sum;
        free((*stack)->prev);
        (*stack)->prev = NULL;
}

/**
 * mul_nodes - adds to nodes
 * @stack: pointer to pointer pointing to stack top node
 * @line_number: line number
 */
void mul_nodes(stack_t **stack, unsigned int line_number)
{
        int sum;

        if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
                more_err(8, line_number, "mul");
        (*stack) = (*stack)->next;
        sum = (*stack)->n * (*stack)->prev->n;
        (*stack)->n = sum;
        free((*stack)->prev);
        (*stack)->prev = NULL;
}

