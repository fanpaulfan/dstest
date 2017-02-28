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

/* inorder can print sorted data list */
void in_order_travel(struct node* current)
{
        if (current != NULL) {
                in_order_travel(current->left);
                printf("[%d]", current?current->value:-1);
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
}

struct node* find_data(int data)
{
	struct node* current = head;

	while(current != NULL) {
		if (data > current->value) {
			current = current->right;
		} else if (data < current->value) {
			current = current->left;
		} else { // val == current->data
			return current;
		}
	}

	return NULL;
}

struct node* sub_right_smallest(struct node* candidate)
{
	while (candidate->left != NULL) {
		candidate = candidate->left;
	}

	return candidate;
}

int delete_data(int data)
{
	struct node* current = head;
	struct node* parent = NULL;
	struct node* substitute = NULL;

	while (current != NULL) {

		if (data == current->value) { //hit !!

			if (current->left == NULL || current->right == NULL) {

				if (current->left == NULL && current->right == NULL) { //no child
					printf("no child\n");
					substitute = NULL;
				} else if (current->left == NULL) { // only one child (right)
					printf("only one child (R)\n");
					substitute = current->right;
				} else if (current->right == NULL) { // only one child (left)
					printf("only one child (L)\n");
					substitute = current->left;
				}

			} else { //have two childs
				substitute = sub_right_smallest(current->right);
				printf("found right smallest : %d\n", substitute->value);
				//substitute = sub_left_largest(current->left);
			}


			if (parent == NULL) { //delete head node
				head = substitute;
			} else { //delete non-head node
				if(parent->left == current) {
					printf("parent(%d)->left\n", parent->value);
					parent->left = substitute;
				} else {
					printf("parent(%d)->right\n", parent->value);
					parent->right = substitute;
				}

			}
	
			if (substitute) {
				if (current->left != substitute && substitute->left == NULL)
					substitute->left = current->left;
				if (current->right != substitute && substitute->right == NULL)
					substitute->right = current->right;
			}

			free(current);
			return 1;
		} else if (data > current->value) {
			parent = current;

			current = current->right;
		} else {
			parent = current;
			current = current->left;
		}
	}

	return 0;
}

void main(int args, char* argu[])
{
/*
        5
       / \
      4   6
     /     \
    2       8
   / \     / \
  1   3   7   9

*/
	int data[9] = {5, 6, 4, 8, 2, 3, 7, 1, 9};
	btree_create(9, data);
	int delete_target_val = atoi(argu[1]);
	print_btree();
	printf("find data %d, addr=%X\n", 11, find_data(11));
	printf("delete data %d , %s\n", delete_target_val, delete_data(delete_target_val)?"success":"fail");
	print_btree();
}
