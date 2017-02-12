#include <stdio.h>

int sequential_search(void)
{
	int arr[] = {9,25,33,74,90,15,1,8,42,66,81};
	int query, i;

	printf("which integer you want to query ?\n");
	scanf("%d", &query);

	for ( i = 0 ; i < sizeof(arr) / sizeof(int) ; i++)
		if ( query == arr[i]) {
			printf("%d found in index %d\n", query, i);
			return 1;
		}

	printf("%d is not in this array ! \n", query);
	return 0;
}

int binary_search(void)
{
	int arr[] = {1,8,9,15,25,33,42,66,74,81,90};
	int query, begin, middle, end, i = 0;

	printf("which integer you want to query ?\n");
	scanf("%d", &query);

	begin = 0;
	end = sizeof(arr) / sizeof(int);
	
	while ( begin <= end ) {
		middle = (begin + end) / 2;
		if ( query == arr[middle] ) {
			printf("%d found in index %d\n", query, middle);
			return middle;
		} else if ( query < arr[middle])
			end = middle - 1;
		else //if query > arr[middle] 
			begin = middle + 1;
	}

	printf("%d is not in this array ! \n", query);
}

void main(void)
{
	//sequential_search();
	binary_search();
}
