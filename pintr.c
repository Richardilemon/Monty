#include "monty.h"
/**
 * pintr - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void pintr(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		freedStack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
