#include "monty.h"

/**
 * nop - Nil
 * @stack: Top node of the stack.
 * @line_number: line number of the opcode.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * swap_nodes - Swapping elements of the stack.
 * @stack: top node of the stack.
 * @line_number: line number of the opcode.
 */
void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *nw;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");
	nw = (*stack)->next;
	(*stack)->next = nw->next;
	if (nw->next != NULL)
		nw->next->prev = *stack;
	nw->next = *stack;
	(*stack)->prev = nw;
	nw->prev = NULL;
	*stack = nw;
}

/**
 * add_nodes - Adding the top two elements of the stack.
 * @stack: top node of the stack.
 * @line_number: line number of the opcode.
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int adds;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "add");

	(*stack) = (*stack)->next;
	adds = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = adds;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_nodes - subtracting elements of the stack.
 * @stack: top node of the stack.
 * @line_number: line number of the opcode.
 */
void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int subs;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "sub");


	(*stack) = (*stack)->next;
	subs = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = subs;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_nodes - dividing elements of the stack.
 * @stack: top node of the stack.
 * @line_number: line number of the opcode.
 */
void div_nodes(stack_t **stack, unsigned int line_number)
{
	int divs;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "div");

	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	divs = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = divs;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
