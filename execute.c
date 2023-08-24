#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", pushr}, {"pall", pallr}, {"pint", pintr},
				{"pop", popr},
				{"swap", swapr},
				{"add", addr},
				{"nop", nopr},
				{"sub", subr},
				{"div", divr},
				{"mul", mulr},
				{"mod", modr},
				{"pchar", pcharr},
				{"pstr", pstrr},
				{"rotl", rotlr},
				{"rotr", rotrr},
				{"queue", queuer},
				{"stack", stackr},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		freedStack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
