/*
 * 計算陣列中所有元素的立方和
 *
 * @Author: Alan Titor
 * @Date: 2013/8/30
 */


#include <stdio.h>

int pow1(int bas, int exp);

int main(void)
{
	int array[6] = {0};
	int array_size = 6;
	int buf = 0;
	int sum = 0;

	int count = 0;
	for (count = 0; count < array_size; count++)
	{
		scanf("%d", &buf);
		array[count] = buf;
	}

	for (count = 0; count < array_size; count++)
	{
		sum += pow1(array[count], 3);
	}

	printf("%d", sum);

	return 0;
}


int pow1(int bas, int exp)
{
	int ans = bas;

	if (exp == 0)  return 1;

	if (exp == 1)  return bas;

	while (exp > 1)
	{
		ans *= bas;
		exp--;
	}

	return ans;	
}
