#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct stack
{
	char element;
	struct stack *nextNode;

} stack;

// This is a linked list with a header node
stack *createStack()
{
	stack *st = malloc(sizeof(stack));
	st->element = '\0';
	st->nextNode = NULL;

	return st;
}

int stack_is_empty(stack *st)
{
	if(st->nextNode == NULL) return 1;
	return 0;
}

void push(stack *st, char valueToInsert)
{
	stack *newNode = malloc(sizeof(stack));
	newNode->nextNode = st->nextNode;
	newNode->element = valueToInsert;
	st->nextNode = newNode;

}

char pop(stack *st)
{
	if(stack_is_empty(st)) return -1;

	stack *trashNode = malloc(sizeof(stack));
	trashNode = st->nextNode;

	char elementAtTheTopOfStack = trashNode->element;
	st->nextNode = trashNode->nextNode;

	free(trashNode);

	return elementAtTheTopOfStack;
}

char get_first_element(stack* st) {
	if (!stack_is_empty(st))
		return st->nextNode->element;
	
	return '\0';
}

void print_stack_state(stack* st) {
	for(stack *i = st->nextNode; i != NULL; i = i->nextNode) {
		printf("%c", i->element);
	}
	printf("\n");
}

int main() {
	char* input = malloc(100);
	while(scanf("%s", input)!= EOF) {
		stack* st = createStack();
		int input_length = strlen(input);

		for(int i = 0; i < input_length; i++) {
			if(!stack_is_empty(st)) {
				if(get_first_element(st) != toupper(input[i]))
					pop(st);
				else push(st, toupper(input[i]));

			} else push(st, toupper(input[i]));

			if(!stack_is_empty(st)) 
				print_stack_state(st);
			else printf("nil\n");
		}

		if(stack_is_empty(st)) {
			printf("Aceito\n");
		} else printf("Rejeito\n");

		free(st);
	}
	exit(0);
}
