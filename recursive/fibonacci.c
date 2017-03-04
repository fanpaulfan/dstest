#include <stdio.h>

/*
 * 0,1,1,2,3,5,8,13
 * F(0) = 0
 * F(1) = 1
 * F(2) = 1
 * F(3) = 2
 * F(4) = 3
 * ... etc.
 */

int fibonacci_recursive(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
		
/*
 * e.g. n = 4
 * f(4)
 * return f(3)                 +   f(2)
 *        f(2)       +f(1)
 *        f(1)+f(0)  + 1
 *         1  + 0 
 *                          2 
 *                                 f(1)+f(0)
 *                                  1  + 0
 *                                           1
 *                                  +               3
 */
}

int fibonacci_loop(int n)
{
	int f[n];
	int i;

	f[0] = 0;
	f[1] = 1;
	
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	for (i = 2 ; i <= n ; i++) {
		f[i] = f[i-1] + f[i-2];
	}

	return f[n];
}

int main(void)
{
	int n;
	printf("please enter n :\n");
	scanf("%d", &n);
	printf("by recursive, F(%d) = %d \n", n, fibonacci_recursive(n));
	printf("by loop, F(%d) = %d \n", n, fibonacci_loop(n));
	return 0;
}
