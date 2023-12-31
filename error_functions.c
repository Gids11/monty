#include "monty.h"

/**
 * err - Prints appropiate error messages determined by their error code.
 * @error_code: The error codes are the following:
 * (1) ~> The user does not give any file or more than one file to the program.
 * (2) ~> The file provided is not a file that can be opened or read.
 * (3) ~> The file provided contains an invalid instruction.
 * (4) ~> When the program is unable to malloc more memory.
 * (5) ~> When the parameter passed to the instruction "push" is not an int.
 * (6) ~> When the stack it empty for pint.
 * (7) ~> When the stack it empty for pop.
 * (8) ~> When stack is too short for operation.
 */
void err(int error_code, ...)
{
	va_list a;
	char *op;
	int num;

	va_start(a, error_code);
	switch (error_code)
	{
		case 1:
			printf("USAGE: monty file\n");
			break;
		case 2:
			printf("Error: Can't open file %s\n",
				va_arg(a, char *));
			break;
		case 3:
			num = va_arg(a, int);
			op = va_arg(a, char *);
			printf("L%d: unknown instruction %s\n", num, op);
			break;
		case 4:
			printf("Error: malloc failed\n");
			break;
		case 5:
			printf("L%d: usage: push integer\n", va_arg(a, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - handles errors.
 * @error_code: The error codes are the following:
 * (6) ~> When the stack it empty for pint.
 * (7) ~> When the stack it empty for pop.
 * (8) ~> When stack is too short for operation.
 * (9) ~> Division by zero.
 */
void more_err(int error_code, ...)
{
	va_list a;
	char *op;
	int num;

	va_start(a, error_code);
	switch (error_code)
	{
		case 6:
			printf("L%d: can't pint, stack empty\n",
				va_arg(a, int));
			break;
		case 7:
			printf("L%d: can't pop an empty stack\n",
				va_arg(a, int));
			break;
		case 8:
			num = va_arg(a, unsigned int);
			op = va_arg(a, char *);
			printf("L%d: can't %s, stack too short\n", num, op);
			break;
		case 9:
			printf("L%d: division by zero\n",
				va_arg(a, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - handles errors.
 * @error_code: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void string_err(int error_code, ...)
{
	va_list a;
	int num;

	va_start(a, error_code);
	num = va_arg(a, int);
	switch (error_code)
	{
		case 10:
			printf("L%d: can't pchar, value out of range\n", num);
			break;
		case 11:
			printf("L%d: can't pchar, stack empty\n", num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
