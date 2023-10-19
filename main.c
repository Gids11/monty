#include "monty.h"
stack_t *head = NULL;

/**
 * main - main function
 * @argc: Number of command line arguments.
 * @argv: An array containing the arguments.
 * Return: Always Zero.
 */
int main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
		err(1);
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * free_nodes - Freeing nodes in the stack.
 */
void free_nodes(void)
{
	stack_t *new;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		new = head;
		head = head->next;
		free(new);
	}
}

/**
 * create_node - Creates and populates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *nodes;

	nodes = malloc(sizeof(stack_t));
	if (nodes == NULL)
		err(4);
	nodes->next = NULL;
	nodes->prev = NULL;
	nodes->n = n;
	return (nodes);
}
