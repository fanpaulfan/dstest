#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* l_link;
	struct node* r_link;
};

struct node* head = NULL;
struct node* tail = NULL;

int insert (int data, int before_data)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	struct node* current = NULL;
	struct node* prev = NULL;

	new_node->data = data;
	
	if (head == NULL) { //first created node
		new_node->l_link = NULL;
		new_node->r_link = NULL;
		head = new_node;
		tail = new_node;
	} else {
		current = head;
		while (current != NULL) {
			if (current->data == before_data) {
				new_node->r_link = current;
				current->l_link = new_node;

				if (prev == NULL) {//insert before first node
                        		new_node->l_link = NULL;
                        		head = new_node;
                		} else { //insert before to normal node
                        		new_node->l_link = prev;
                        		prev->r_link = new_node;
                		}

				return 1;
			}
			prev = current;
			current = current->r_link;
		}

		//no any before_data be found, insert into the tail
		tail->r_link = new_node;
		new_node->l_link = tail;
		tail = new_node;
	}

	return 1;
}

int delete (int input)
{
	struct node* current = head;
	struct node* prev = NULL;

	while (current != NULL) {
		if (current->data == input) {
			if (prev == NULL && current->r_link == NULL) { // single node
                                head = NULL;
                                tail = NULL;
                                break;
			} else if (prev == NULL) { //head node
				head = current->r_link;
				current->r_link->l_link = NULL;
				break;
			} else if (current->r_link == NULL) { //tail node
				tail = current->l_link;
				current->l_link->r_link = NULL;
				break;
			} else { //normal node
				prev->r_link = current->r_link;
				current->r_link->l_link = prev;
				break;
			}
		}
		prev = current;
		current = current->r_link;
	}

	free(current);
	return 1;
}

void inverse(void)
{
}

void print_list(int start_from_head)
{
	printf("\n###################\n");
	struct node* current;

	if (start_from_head) {
		current = head;
		while (current != NULL) {
			printf("%d,", current->data);
			current = current->r_link;
		}
	} else {
		current = tail;
		while (current != NULL) {
			printf("%d,", current->data);
			current = current->l_link;
		}
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
		print_list(1);
		print_list(0);
	} while (choose != -1);
}
