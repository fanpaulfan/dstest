#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node* next;
};

struct node* head;

void push (int input)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));

	new_node->value = input;

	if(head == NULL) {
		new_node->next = NULL;
	} else {
		new_node->next = head;
	}

	head = new_node;
}

int pop (void)
{
	struct node* current = head;
	int data = 0;

	if (current != NULL) {
		head = current->next;
		data = current->value;
		free(current);
		current = NULL;
	}

	return data;
}

void print_stack(void)
{
	printf("\n");
	struct node* current = head;
	while (current != NULL) {
		printf("[%d]", current->value);
		current = current->next;
	}
	printf("\n");
}

void main()
{
	int input = 0;

	while (1) {
		printf("pleae enter a integer :\n");
		scanf("%d", &input);
		if (input == -1)
			break;
		push(input);
		print_stack();
	}

	printf("pop: %d\n", pop() );
}
