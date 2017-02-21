#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node* left;
	struct node* right;
};

struct node* head = NULL;

void btree_insert(int val)
{
	printf("insert %d to btree\n", val);

	struct node* new_node = NULL;
	struct node* current = NULL;
	int done = 0;
	
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->value = val;
	new_node->left = NULL;
	new_node->right = NULL;

	if (head == NULL) { //root node
		head = new_node;
	} else {
		current = head;
		while (!done) {
			if (val > current->value) { //right sub-tree
				if (current->right != NULL) {
					current = current->right;
				} else {
					current->right = new_node;
					done = 1;
				}	
			} else { //left sub-tree
				if (current->left != NULL) {
					current = current->left;
				} else {
					current->left = new_node;
					done = 1;
				}
			}
		}
	}
}

void btree_create(int size, int* data)
{
	int i = 0;
	while(i < size) {
		btree_insert(data[i++]);
	}
}

void pre_order_travel(struct node* current)
{
	if (current != NULL) {
		printf("[%d]", current->value);
		pre_order_travel(current->left);
		pre_order_travel(current->right);
	}
}

void in_order_travel(struct node* current)
{
        if (current != NULL) {
                in_order_travel(current->left);
                printf("[%d]", current->value);
                in_order_travel(current->right);
        }
}

void post_order_travel(struct node* current)
{
        if (current != NULL) {
                post_order_travel(current->left);
                post_order_travel(current->right);
                printf("[%d]", current->value);
        }
}

void print_btree()
{
	if (head != NULL) {
		pre_order_travel(head);
		printf("\n");
		in_order_travel(head);
		printf("\n");
		post_order_travel(head);
		printf("\n");
	}
/*
	struct node* ptr;
	
	printf("show root : [%d]\n", head->value);

	printf("show left sub-tree\n");
	ptr = head->left;
	while(ptr != NULL) {
		printf("[%d]\n", ptr->value);
		ptr = ptr->left;
	}
	
	printf("show right sub-tree\n");
	ptr = head->right;
	while(ptr != NULL) {
		printf("[%d]\n", ptr->value);
		ptr = ptr->right;
	}
*/
}

void main(void)
{
	int data[9] = {5, 6, 4, 8, 2, 3, 7, 1, 9};
	btree_create(9, data);
	print_btree();
}
