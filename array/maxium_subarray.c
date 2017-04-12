#include <stdio.h>
#include <limits.h>

int max(int a, int b)
{
	return (a>b?a:b);
}

int max3(int a, int b, int c)
{
	return max(max(a, b), c);
}

int maxCrossingSum(int arr[], int l, int m, int h)
{
	int sum = 0;
	int left_sum = INT_MIN;
	int i;

	for (i = m; i >=l; i--) {
		sum += arr[i];
		if ( sum > left_sum )
			left_sum = sum;
	}

	sum = 0;
	int right_sum = INT_MIN;
	for ( i = m+1 ; i <= h ; i++ ) {
		sum += arr[i];
		if ( sum > right_sum )
			right_sum = sum;
	}

	return left_sum + right_sum;
}

int maxSubArraySum(int arr[], int l, int h)
{
	if(l == h)
		return arr[l];

	int m = (l+h)/2;

	return max3(maxSubArraySum(arr, l, m),
			maxSubArraySum(arr, m+1, h),
			maxCrossingSum(arr, l, m, h));
}

int violence_sum(int arr[], int size)
{
	int i,j,k;
	int sum, max_sum = INT_MIN;

	for ( i = 1 ; i <= size ; i++) { //size of work window
		for ( j = 0 ; j < size - i + 1; j++) {

			sum = 0;

			for ( k = j ; k < j+i ; k++ )
				sum += arr[k];

			if ( sum > max_sum )
				max_sum = sum;
		}
	}

	return max_sum;
}

/*
 * kadane algo can NOT apply in array with all negative value
 */
int kadane_algo(int array[], int size)
{
	int sum = 0;
	int max_sum = array[0];
	int i;
	for (i = 0; i < size; ++i)
	{
		sum += array[i];
		sum = max(0, sum);
		max_sum = max(sum, max_sum);
	}

	return max_sum;
}

int main()
{
	int arr[] = {1,5,-7,-9,2,-1,3,5,-5,10,-8};
	//int arr[] = {2,3,4,5,1,7};
	//int arr[] = {-2,-3,-4,-5,-1,-7};
	int n = sizeof(arr)/sizeof(arr[0]);

	printf("divide and conquer result : %d\n", maxSubArraySum(arr, 0, n-1));
	printf("violence's result : %d\n", violence_sum(arr, n));
	printf("kadane's result : %d\n", kadane_algo(arr, n));

	return 0;
}
