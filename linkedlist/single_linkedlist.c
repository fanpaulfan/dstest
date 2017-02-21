#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* head = NULL;

int insert (int data, int before_data)
{
	struct node* new_node;
	struct node* current = head;
	struct node* prev = NULL;

	if (data < 0 || before_data < 0)
		return 0;

	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;

	if (head == NULL) { // first inserted node
		head = new_node;
		printf("data %d insert to head\n", data);
		return 1;
	}

	while (current != NULL && current->data != before_data) {
		prev = current;
		current = current->next;
	}

	if (prev == NULL) { //only one node
		new_node->next = head;
		head = new_node;
	} else {
		new_node->next = current;
		prev->next = new_node;
	}

	printf("data %d insert before %d finish\n", data, before_data);
	return 1;
}

int delete (int input)
{
	struct node* current = head;
	struct node* prev = NULL;

	if (head == NULL)
		return 0;

	while (current != NULL) {
		if (current->data == input) {
			if (prev == NULL) {
				head = current->next;
				break;
			} else {
				prev->next = current->next;
				break;
			}
		}	
		prev = current;
		current = current->next;
	}

	if (current != NULL) {
		free(current);
		return 1;
	} else
		return 0;
}

void inverse(void)
{
	struct node* current = head;
	struct node* prev = NULL;
	struct node* forward = NULL;
	
	while (current != NULL) {
		forward = current->next;
		current->next = prev;
		prev = current;
		current = forward;
	}
	
	head = prev;
}

void print_list()
{
	printf("\n###################\n");
	struct node* current = head;
	while (current != NULL) {
		printf("%d,", current->data);
		current = current->next;
	}
	printf("\n###################\n");
}

void menu(int choose)
{
	int input, before;
	switch(choose) {
		case 1:
			printf("enter data: [input_val] [before_val]\n");
			scanf("%d %d", &input, &before);
			insert(input, before);
			break;
		case 2:
			printf("enter data you want to delete: [input_val]\n");
			scanf("%d", &input);
			delete(input);
			break;

		case 3:
			inverse();
			break;
	}
}

void main(void)
{
	int choose;

	do {
		printf("please enter your choose: -1)exit 1)insert 2)delete 3)inverse\n");
		scanf("%d", &choose);
		menu(choose);
		print_list();
	} while (choose != -1);
}
