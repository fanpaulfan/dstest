#include <stdio.h>
#include <stdlib.h>

struct node {
	char value;
	struct node* next;
};

struct node* head;

int priority (char input)
{
	int level;
	switch (input) {
		case '(' : level = 1; break;
		case '+' : level = 2;
		case '-' : level = 2; break;
		case '*' : level = 3;
		case '/' : level = 3; break;
		default : level = 0;
	}

	return level;
}

int is_operator (char input)
{
	int is_op;

	switch (input) {
		case '(' :
		case ')' :
		case '+' :
		case '-' :
		case '*' :
		case '/' :
			is_op = 1; //operator
			break;
		defalut :
			is_op = 0; //digital
			break;	
	}
	return is_op;
}

void push (char input)
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

char pop (void)
{
	struct node* current = head;
	char data;	

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
	struct node* current = head;
	while (current != NULL) {
		printf("%c", current->value);
		current = current->next;
	}
	printf("\n");
}

void main()
{
	char input;
	char arr[] = "(a+b)*(c+d)";
	int i = 0;
	char tmp;
	struct node* current = NULL;

	while (1) {
		input = arr[i++];
		
		if (input == '\0')
			break;

		if(is_operator(input)) {
			if (head == NULL || input == '(') {
				push(input);
			} else if (input == ')') {
				while ((tmp = pop()) != '(') {
					if (tmp != '(')
						printf("%c", tmp);
				}
			} else {
				while ((tmp = pop())) {
					if (priority(input) <= priority(tmp)) {
						printf("%c", tmp);
					} else {
						push(tmp);
						break;
					}
				}
				push(input);
			}
		} else {
			printf("%c", input);
			//print_stack();
		}
	}

	if (head != NULL)
		print_stack();	

	printf("\n");
}
