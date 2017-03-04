#include <stdio.h>

/*
 * 1*2 + 2*3 + ... + (n-1)*n
 * e.g. n = 4
 * = 1*2 + 2*3 + 3*4
 * = 2   + 6   + 12
 * = 20
 */

int n_n_1_sum_loop(int n)
{
	int i;
	int total = 0;
	
	for (i = n ; i > 0 ; i--) {
		total += i*(i-1);		
	}

	return total;
}

int n_n_1_sum_recursive(int n)
{
	if (n <= 1)
		return 0;
	else
		return n * (n-1) + n_n_1_sum_recursive(n-1);
}

void main(void)
{
	int n;
	printf("please enter n :\n");
	scanf("%d", &n);
	printf("sum by loop = %d\n", n_n_1_sum_loop(n));
	printf("sum by recursive = %d\n", n_n_1_sum_recursive(n));
}
