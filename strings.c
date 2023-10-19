#include "monty.h"

/**
 * print_char - Printing Ascii values.
 * @stack: top node pointer
 * @line_number: line number of the opcode.
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	int asc_v;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);

	asc_v = (*stack)->n;
	if (asc_v < 0 || asc_v > 127)
		string_err(10, line_number);
	printf("%c\n", asc_v);
}

/**
 * print_str - Prints a string.
 * @stack: top node pointer
 * @ln: line number of the opcode.
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int asc_v;
	stack_t *new;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	new = *stack;
	while (new != NULL)
	{
		asc_v = new->n;
		if (asc_v <= 0 || asc_v > 127)
			break;
		printf("%c", asc_v);
		new = new->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: top node pointer
 * @ln: line number of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *new;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	new = *stack;
	while (new->next != NULL)
		new = new->next;

	new->next = *stack;
	(*stack)->prev = new;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Changes the last node to the top.
 * @stack: top node pointer.
 * @ln: line number of of the opcode.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *new;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	new = *stack;
	while (new->next != NULL)
		new = new->next;
	new->next = *stack;
	new->prev->next = NULL;
	new->prev = NULL;
	(*stack)->prev = new;
	(*stack) = new;
}
