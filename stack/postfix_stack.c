#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node* next;
};

struct node* head;

int pop(void);

int calculate (char input)
{
	int a,b;

	a = pop();
	b = pop();

	switch (input) {
		case '+' : return (a + b);
		case '-' : return (a - b);
		case '*' : return (a * b);
		case '/' : return (a / b);
	}

	return 0;
}

int is_operator (char input)
{
	int is_op;

	switch (input) {
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
	int data;

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
		printf("[%d]", current->value);
		current = current->next;
	}
	printf("\n");
}

void main()
{
	char input, choice;
	int input_int = 0;
	char arr[] = {'6', '7', '*', '4', '5', '+', '+','0'};
	int i = 0;
	int tmp_rst;

	while (1) {
		input = arr[i++];
/*
		printf("pleae enter a char :\n");

		scanf("%c", &input);
		do
		{
			choice = getchar();
			printf("%d", (int)choice);
		} while (choice == '\n');
*/
		input_int = input - '0';

		if (input_int == 0)
			break;

		if(is_operator(input)) {
			tmp_rst = calculate(input);
			push(tmp_rst);
			printf("calculate rst is %d\n", tmp_rst);
		} else {
			push(input_int);
		}

		print_stack();
	}
}
