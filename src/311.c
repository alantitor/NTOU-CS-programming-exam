/*
 * 數制轉換
 *
 * @Author: Alan Titor
 * @Date: 2013/8/30
 */


#include <stdio.h>


int main(void)
{
	long number = 0, unit = 0;

	//  read input data
	scanf("%d %d", &unit, &number);

	char array[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	char result[64] = { '\n' };
	int result_index = 0;

	while (number != 0)
	{
		result[result_index++] = array[number % unit];
		number /= unit;
	}

	int count = result_index - 1;
	for (count; count >= 0; count--)
	{
		printf("%c", result[count]);
	}
	printf("\n");

	return 0;
}
