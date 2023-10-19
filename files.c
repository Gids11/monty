#include "monty.h"

/**
 * open_file - Opens a file.
 * @file_name: String with the name of the file.
 */

void open_file(char *file_name)
{
	int _check;
	FILE *fd;

	if (file_name == NULL)
		err(2, file_name);
	_check = access(file_name, R_OK);
	if (_check == -1)
		err(2, file_name);
	fd = fopen(file_name, "r");
	if (fd == NULL)
		err(2, file_name);

	read_file(fd);
	fclose(fd);
}

/**
 * read_file - Reads the content of a file line by line.
 * @fd: Pointer to a file descriptor of an open file
 */

void read_file(FILE *fd)
{
	int line_n;
	int format;
	char *line_prt;
	size_t n;

	line_prt = NULL;
	n = 0;
	format = 0;

	if (fd == NULL)
		err(2, "file_name");

	for (line_n = 1; getline(&line_prt, &n, fd) != EOF; line_n++)
	{
		format = interpret_line(line_prt, line_n, format);
	}
	free(line_prt);
}


/**
 * interpret_line - Separates each line into tokens to determine
 * which function to call.
 * @lineptr: String representing a line in a file.
 * @line_number: Line number for the opcode.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */
int interpret_line(char *lineptr, int line_number, int format)
{
	const char *delim;
	char *opcode;
	char *value_;

	if (lineptr == NULL)
		err(4);
	delim = "\n ";
	opcode = strtok(lineptr, delim);

	if (opcode == NULL)
		return (format);
	value_ = strtok(NULL, delim);

	if (strcmp(opcode, "queue") == 0)
		return (1);
	else if (strcmp(opcode, "stack") == 0)
		return (0);

	find_func(opcode, value_, line_number, format);
	return (format);
}

/**
 * find_func - Finds the appropite function to run the opcode instructions.
 * @opcode: The operation code, It could be push, pall, ...
 * @value: The possible value for the operation.
 * @ln: Line number for the opcode.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void find_func(char *opcode, char *value, int ln, int format)
{
	int b;
	int a;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;
	for (a = 1, b = 0; func_list[b].opcode != NULL; b++)
	{
		if (strcmp(opcode, func_list[b].opcode) == 0)
		{
			call_fun(func_list[b].f, opcode, value, ln, format);
			a = 0;
		}
	}
	if (a == 1)
		err(3, ln, opcode);
}

/**
 * call_fun - Calls the required function.
 * @f: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_fun(op_func f, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int a;
	int b;

	a = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			a = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (b = 0; val[b] != '\0'; b++)
		{
			if (isdigit(val[b]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * a);
		if (format == 0)
			f(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		f(&head, ln);
}
