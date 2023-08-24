#include "monty.h"
/**
* freedStack - frees a doubly linked list
* @head: head of the stack
*/
void freedStack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
