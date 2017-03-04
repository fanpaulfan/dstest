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

void establish_list(int size, int* data)
{
        int i = 0;
        while(i < size) {
                insert(data[i++], 100);
        }
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

#define N 2

/*
 * 1->2->3->4->5->6 N=1
 * 2->1->4->3->6->5 N=2 , 4-1=3
 * 3->2->1->6->5->4 N=3 , 6-1=5
 */
int quiz1(struct node* prev, struct node* curr, int cnt)
{
	struct node* forward = NULL;

	if (cnt == N) {
		printf("I am new head (%d)\n", cnt);
		head = curr;
	}

	printf("cnt=%d, head-data=%d\n", cnt, head->data);

	if (cnt % N == 0) { //even
		forward = curr->next;

		curr->next = prev;

		prev = curr;
		curr = forward;
	} else { //N's
		forward = curr->next;
		
		struct node* tmp = curr->next;
		int i = 1;

		while (i < 2*N-1) {
			if(tmp && tmp->next) {
				tmp = tmp->next;
			} else {
				break;
			}	
			i++;
		}
/*
		//N = 2:
		if(curr->next != NULL && curr->next->next != NULL && curr->next->next->next != NULL)
			curr->next = curr->next->next->next;
		else if (curr->next != NULL && curr->next->next != NULL)
			curr->next = curr->next->next;
*/
		curr->next = tmp;
		prev = curr;
		curr = forward;
	}

	if (curr == NULL)
                return 1;

	cnt++;
	quiz1(prev, curr, cnt);
}

void main() {
	int input[] = {1,2,3,4,5,6,7,8,9};

	printf("array size : %ld\n", sizeof(input)/sizeof(input[0]));
	establish_list(sizeof(input)/sizeof(input[0]), input);
	print_list();
	quiz1(NULL, head, 1);
	print_list();
}
