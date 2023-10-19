#include "monty.h"

/**
 * mul_nodes - multiplies elements of the stack.
 * @stack: top node of the stack.
 * @line_number: line number of the opcode.
 */
void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int prod;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	prod = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = prod;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_nodes - finds mod of elements of the stack.
 * @stack: top node of the stack.
 * @line_number: line number of the opcode.
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int mods;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "mod");


	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	mods = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = mods;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
