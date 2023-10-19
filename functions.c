#include "monty.h"

/**
 * pop_top - popping
 * @stack: top node of the stack.
 * @line_number: line number of of the opcode.
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	new = *stack;
	*stack = new->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(new);
}

/**
 * print_top - Printing top node of the stack.
 * @stack: top node of the stack.
 * @line_number: line number of of the opcode.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}

/**
 * add_to_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *new;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	new = head;
	head = *new_node;
	head->next = new;
	new->prev = head;
}

/**
 * print_stack - prints the stack.
 * @stack: top node pointer
 * @line_number: line number of the opcode.
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	new = *stack;
	while (new != NULL)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
}


/**
 * add_to_queue - adding new node to queue.
 * @new_node: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *new;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	new = head;
	while (new->next != NULL)
		new = new->next;
	new->next = *new_node;
	(*new_node)->prev = new;
}
