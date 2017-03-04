#include <stdio.h>

//Big-O(N)
void n_sum_loop(int n)
{
	int i;
	int sum = 0;
	
	for (i = 1 ; i <= n ; i ++) {
		sum += i;
	}

	printf("sum by loop = %d\n", sum);
}

//Big-O(N)
int n_sum_recursive(int n)
{
	if (n < 1)
		return 0;
	else
		return n + n_sum_recursive(n-1);
/*
 * e.g. n = 4 
 * return 4 + n_sum_recursive(3)
 *            return 3 + n_sum_recursive(2)
 *                       return 2 + n_sum_recursive(1)   
 *                                  return 1 + recursive(0)
 *                                             return 0
 * so that
 * return 4 +        3 +        2 +        1 +        0
 * return 10
 */
}

//Big-O(1)
int n_sum_math(int n)
{
	return (1+n)*n/2;
}

int main(void)
{
	int n;
	printf("please enter n :\n");
	scanf("%d", &n);
	n_sum_loop(n);
	printf("sum by recursive = %d\n", n_sum_recursive(n));
	printf("sum by math = %d\n", n_sum_math(n));
	return 0;
}
