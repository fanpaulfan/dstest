#include <stdio.h>

int n_factorial_loop(int n)
{
	int i;
	int total = 1;

	for (i = n ; i > 0 ; i--) {
		total *= i;
	}

	return total;
}

int n_factorial_recursive(int n)
{
	if (n == 1)
		return 1;
	else
		return n * n_factorial_recursive(n-1);
}

void main(void)
{
	int n;
	printf("please enter n :\n");
	scanf("%d", &n);
	printf("n factorial by loop = %d\n", n_factorial_loop(n));
	printf("n factorial by recursive = %d\n", n_factorial_recursive(n));
}
