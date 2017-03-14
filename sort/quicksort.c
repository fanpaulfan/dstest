#include <stdio.h>

void q_sort(int *data, int left, int right)
{
	int partition, temp, i, j, k;

	if ( left < right ) {
		i = left;
		j = right + 1;
		partition = data[left];

		do {
			do {
				i++;
			} while (data[i] < partition);

			do {
				j--;
			} while (data[j] > partition);

			if (i < j) {
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		} while (i < j);

		temp = data[left];
		data[left] = data[j];
		data[j] = temp;

		q_sort(data, left, j-1);
		q_sort(data, j+1, right);
	}
}

int main(void)
{
	int data[] = {4,5,1,3,6,2,8,7};

	q_sort(data, 0, 7);

	int i;
	for (i = 0 ; i < 8 ; i++) {
		printf("%d,", data[i]);
	}
	printf("\n");
}
