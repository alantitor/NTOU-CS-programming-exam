/*
 * 永遠不會死的老鼠
 *
 * @Author: Alan Titor
 * @Date: 2013/9/5
 */


/*
 * Think of "Fibonacci series"
 *
 * N		0 1 2 3 ...
 * female	1 1 2 3
 * male		0 1 2 4
 *
 * Algorithm:
 *		female number = M_(N-1) + 1
 *		male number   = M_(N-1) + F_(N-1)
 *		N >= 1;
 *
 * Problem:
 *		unsigned long long int size: 0 to 18,446,744,073,709,551,615
 */


#include <stdio.h>


unsigned long long int mouse_number[2][65536] = {0};

int main(void)
{
	unsigned int N = 0;
	mouse_number[0][0] = 1;
	mouse_number[1][0] = 0;
	mouse_number[0][1] = 1;
	mouse_number[1][1] = 1;

	scanf("%d", &N);

	if(N == 0 || N == 1) {
		printf("%d %d\n", mouse_number[1][N], mouse_number[0][N]);
	} else {
		unsigned int index = 0;
		for(index = 2; index <= N; index++) {
			mouse_number[0][index] = mouse_number[1][index - 1] + 1;
			mouse_number[1][index] = mouse_number[0][index - 1] + mouse_number[1][index - 1];
		}

		printf("%lld %lld\n", mouse_number[1][N], mouse_number[0][N]);
	}

	return 0;
}
